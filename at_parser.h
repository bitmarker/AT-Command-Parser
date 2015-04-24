#ifndef AT_PARSER_H
#define AT_PARSER_H

#include "my_string.h"

#define AT_MAX_TEMP_STRING	50

typedef char (*at_command_callback)(unsigned char *value);

#define AT_OK 		0
#define AT_ERROR 	1

#define AT_PARSER_STATE_COMMAND 	0
#define AT_PARSER_STATE_TEST		1
#define AT_PARSER_STATE_READ		2
#define AT_PARSER_STATE_WRITE		3
#define AT_PARSER_STATE_EQUAL		4

#ifndef AT_COMMAND_MARKER
#define AT_COMMAND_MARKER "AT+"
#endif

unsigned long at_hash(string_t str);
void at_register_command(string_t command, at_command_callback getter, at_command_callback setter, at_command_callback test, at_command_callback execute);


#endif