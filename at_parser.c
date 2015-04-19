#include "at_parser.h"

typedef struct _at_command
{
	unsigned long hash;
	at_command_callback setter;
	at_command_callback getter;
} AT_COMMAND;

#ifndef AT_COMMANDS_NUM
#define AT_COMMANDS_NUM 10
#endif

AT_COMMAND at_registered_commands[AT_COMMANDS_NUM];

unsigned long at_hash(unsigned char *str)
{
	unsigned long hash = 5381;
	int c;

	while((c = *str++))
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

	return hash;
}

void at_register_command(unsigned char * command, at_command_callback getter, at_command_callback setter)
{
	int i;
	AT_COMMAND new_cmd;
	new_cmd.hash = at_hash(command);
	new_cmd.getter = getter;
	new_cmd.setter = setter;
	
	for(i = 0; i < AT_COMMANDS_NUM; i++)
	{
		if(at_registered_commands[i].hash == 0)
		{
			at_registered_commands[i] = new_cmd;
			return;
		}
	}
}

char at_execute_command(unsigned char *command, char *value, char set_value)
{
	int i;
	
	char result = AT_ERROR;
	
	unsigned long hash = at_hash(command);
	
	for(i = 0; i < AT_COMMANDS_NUM; i++)
	{
		if(at_registered_commands[i].hash == hash)
		{
			if(set_value)
			{
				result = at_registered_commands[i].setter(value);
			}
			else
			{
				result = at_registered_commands[i].getter(value);				
			}
		}
	}
	
	return result;
}

