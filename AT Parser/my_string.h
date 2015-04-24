#ifndef __MY_STRING__
#define __MY_STRING__

#include "types.h"

int16_t ms_str_find(string_t haystack, string_t needle);
void ms_array_slice_to_string(string_t array, uint16_t start, uint16_t end, unsigned char *ret);
uint16_t ms_strlen(string_t string);

#endif