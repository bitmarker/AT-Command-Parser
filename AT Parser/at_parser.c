#include "at_parser.h"

typedef struct _at_command
{
    unsigned long hash;
    at_callback setter;
    at_callback getter;
    at_callback test;
    at_callback execute;
} AT_COMMAND;

#ifndef AT_COMMANDS_NUM
#define AT_COMMANDS_NUM 10
#endif

AT_COMMAND at_registered_commands[AT_COMMANDS_NUM];

unsigned long at_hash(string_t str)
{
    unsigned long hash = 5381;
    int c;

    while((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

void at_register_command(string_t command, at_callback getter, at_callback setter, at_callback test, at_callback execute)
{
    int i;
    AT_COMMAND new_cmd;
    new_cmd.hash = at_hash(command);
    new_cmd.getter = getter;
    new_cmd.setter = setter;
    new_cmd.execute = execute;
    new_cmd.test = test;
    
    for(i = 0; i < AT_COMMANDS_NUM; i++)
    {
        if(at_registered_commands[i].hash == 0)
        {
            at_registered_commands[i] = new_cmd;
            return;
        }
    }
}

char at_execute_command(string_t command, unsigned char *value, unsigned char type)
{
    int i;
    
    char result = AT_ERROR;
    
    unsigned long hash = at_hash(command);

    for(i = 0; i < AT_COMMANDS_NUM; i++)
    {
        if(at_registered_commands[i].hash == hash)
        {            
            switch(type)
            {
                case AT_PARSER_STATE_WRITE:
                    if(at_registered_commands[i].setter == 0)
                    {
                        return AT_ERROR;
                    }
                    result = at_registered_commands[i].setter(value);
                    break;
                case AT_PARSER_STATE_READ:
                    if(at_registered_commands[i].getter == 0)
                    {
                        return AT_ERROR;
                    }
                    result = at_registered_commands[i].getter(value);
                    break;
                case AT_PARSER_STATE_TEST:
                    if(at_registered_commands[i].test == 0)
                    {
                        return AT_ERROR;
                    }
                    result = at_registered_commands[i].test(value);
                    break;
                case AT_PARSER_STATE_COMMAND:
                    if(at_registered_commands[i].execute == 0)
                    {
                        return AT_ERROR;
                    }
                    result = at_registered_commands[i].execute(value);
                    break;            
                default:
                    result = AT_ERROR;
            }
        }
    }
    
    return result;
}

/*
 
 AT+COMMAND=? -> List
 AT+COMMAND=VALUE -> Write
 AT+COMMAND? -> Read
 AT+COMMAND -> Execute
 
 */

char at_parse_line(string_t line, unsigned char *ret)
{
    uint16_t i;
    
    char result = AT_ERROR;
    
    char state = AT_PARSER_STATE_COMMAND;
    
    int16_t start = ms_str_find(line, (string_t)AT_COMMAND_MARKER);
    
    uint16_t line_len = ms_strlen(line);
    
    int16_t index_write_start = -1;
    
    int16_t index_command_end = line_len - 1;
    
    unsigned char temp[AT_MAX_TEMP_STRING];
    
    if(start >= 0)
    {
        // Skip the marker
        start += ms_strlen((string_t)AT_COMMAND_MARKER);
        
        for(i = start; i < line_len; i++)
        {
            // Execute 'read' command
            if(line[i] == '?' && state == AT_PARSER_STATE_COMMAND)
            {
                index_command_end = i - 1;
                state = AT_PARSER_STATE_READ;
            }
            else if(line[i] == '=' && state == AT_PARSER_STATE_COMMAND)
            {
                index_command_end = i - 1;

                if(i < (line_len - 1))
                {
                    if(line[i + 1] == '?')
                    {
                        state = AT_PARSER_STATE_TEST;
                    }
                    else
                    {
                        state = AT_PARSER_STATE_WRITE;
                    }
                }
                else
                {
                    return AT_ERROR;                
                }
            }
        }
        
        ret[0] = 0;
        
        switch(state)
        {
            case AT_PARSER_STATE_COMMAND:
            case AT_PARSER_STATE_READ:
            case AT_PARSER_STATE_TEST:
                ms_array_slice_to_string(line, start, index_command_end, temp);
                result = at_execute_command(temp, ret, state);
                break;
            
            case AT_PARSER_STATE_WRITE:
                ms_array_slice_to_string(line, start, index_command_end, temp);
                if(index_write_start <= (line_len - 1))
                {
                    ms_array_slice_to_string(line, index_write_start, line_len - 1, ret);
                    result = at_execute_command(temp, ret, state);
                }
                else
                {
                    result = at_execute_command(temp, ret, state);
                }
                break;
            
            default:
                return AT_ERROR;
        }
    }
    
    
    return result;
}