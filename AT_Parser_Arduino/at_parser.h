#ifndef AT_PARSER_H
#define AT_PARSER_H

#include "my_string.h"

#define AT_MAX_TEMP_STRING	50

typedef char (*at_callback)(unsigned char *value);

#define AT_OK 		                0
#define AT_ERROR 	                1

#define AT_ERROR_STRING                 "ERROR"
#define AT_OK_STRING                    "OK"

#define AT_PARSER_STATE_COMMAND 	0
#define AT_PARSER_STATE_TEST		1
#define AT_PARSER_STATE_READ		2
#define AT_PARSER_STATE_WRITE		3
#define AT_PARSER_STATE_EQUAL		4

#ifndef AT_COMMAND_MARKER
#define AT_COMMAND_MARKER "AT+"
#endif

#ifdef __cplusplus
extern "C"{
#endif

unsigned long at_hash(string_t str);
void at_register_command(string_t command, at_callback getter, at_callback setter, at_callback test, at_callback execute);
char at_parse_line(string_t line, unsigned char *ret);

#ifdef __cplusplus
} // extern "C"
#endif

#endif
