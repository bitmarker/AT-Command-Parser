#ifndef AT_PARSER_H
#define AT_PARSER_H

typedef char (*at_command_callback)(char * value);

#define AT_OK 		0
#define AT_ERROR 	1

unsigned long at_hash(unsigned char *str);


#endif