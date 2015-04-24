#include <stdio.h>
#include "at_parser.h"

char set_flash_port(char * value)
{
	printf("set_flash_port: %s\n", value);
	return AT_OK;
}

char get_flash_port(char * value)
{
	//printf("get_flash_port: %s\n", value);
	strcpy(value, "7");
	return AT_OK;
}

char set_trigger_port(char * value)
{
	printf("set_trigger_port: %s\n", value);	
	return AT_OK;
}

char get_trigger_port(char * value)
{
	strcpy(value, "Wowowow");
	
	printf("get_trigger_port: %s\n", value);	
	return AT_OK;
}

char exec_trigger(char * value)
{
	strcpy(value, "Blink!");
	
	printf("exec_trigger: %s\n", value);	
	return AT_OK;
}

int main(int argc, char **argv)
{
	unsigned char temp[50];
	
	at_register_command("FLPT", (at_callback)get_flash_port, (at_callback)set_flash_port, 0, 0);
	at_register_command("TRPT", (at_callback)get_trigger_port, (at_callback)set_trigger_port, 0, 0);
	at_register_command("TRIG", 0, 0, 0, (at_callback)exec_trigger);
	
    
    char ret = at_parse_line("AT+TRPT=5", temp);
    
    if(ret == AT_OK)
    {
        if(ms_strlen(temp) > 0)
        {
            puts(temp);
        }
        printf("OK");
    }
    else
    {
        printf("ERROR");
    }
    
	
	return 0;
}
