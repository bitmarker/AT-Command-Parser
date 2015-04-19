#include <stdio.h>
#include "at_parser.h"

char set_flash_port(char * value)
{
	printf("set_flash_port: %s\n", value);
	return AT_OK;
}

char get_flash_port(char * value)
{
	printf("get_flash_port: %s\n", value);	
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



int main(int argc, char **argv)
{
	at_register_command("FLPT", (at_command_callback)get_flash_port, (at_command_callback)set_flash_port);
	at_register_command("TRPT", (at_command_callback)get_trigger_port, (at_command_callback)set_trigger_port);
	
	char buff[10];
	
	char ret = at_execute_command("FLPT", buff, 0);
	
	
	
	printf("ret: %d, buf: %s", ret, buff);
	
	return 0;
}
