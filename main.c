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
	char temp[50];
	
	at_register_command("FLPT", (at_command_callback)get_flash_port, (at_command_callback)set_flash_port, 0, 0);
	at_register_command("TRPT", (at_command_callback)get_trigger_port, (at_command_callback)set_trigger_port, 0, 0);
	at_register_command("TRIG", 0, 0, 0, (at_command_callback)exec_trigger);
	
	/*
	char buff[10];
	char ret = at_execute_command("FLPT", buff, 0);
	printf("ret: %d, buf: %s\n\n", ret, buff);
	*/
	
	
	/*
	at_parse_line("AT+FLPT=?");
	at_parse_line("AT+FLPT?");
	at_parse_line("AT+FLPT=5");
	at_parse_line("AT+STRT");
	
	at_parse_line("sjkfjksdAT+STRT");
	
	at_parse_line("sdf,nsdf");
	at_parse_line("s");
	at_parse_line("");
	*/
	
	
	//at_parse_line("XXXXX AT+TEST=?", temp);
	//at_parse_line("...AT+READ?", temp);
	//at_parse_line("AT+WRITE?=7", temp);
	//at_parse_line("AT+WRITE?=Hallo Welt?", temp);
	
	at_parse_line("AT+TRIG", temp);
	
	printf("\ntemp: ");
	printf(temp);
	
	//printf("\nret: %d\n", at_parse_line("AT+EXEC==", temp));
	//
	//printf("\nret: %d\n", at_parse_line("AT+BOO?=", temp));

	
	return 0;
}
