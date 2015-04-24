#include "my_string.h"

#include <stdio.h>

uint16_t ms_strlen(string_t string)
{
	uint16_t i;
	for(i = 0; *string; i++, string++);
	return i;
}

void ms_shift_array(char *array, uint16_t len)
{
	int i;
	for(i = 0; i < len - 1; i++)
	{
		array[i] = array[i + 1];
	}
}

char ms_str_equal(string_t string1, uint16_t len1, string_t string2, uint16_t len2)
{
	int i;
	
	for(i = 0; i < len2; i++)
	{
		if(string1[len1 - len2 + i] != string2[i])
		{
			return 0;
		}
	}
	
	return 1;
}

int16_t ms_str_find(string_t haystack, string_t needle)
{
	int i;
	uint16_t needle_len = ms_strlen(needle);
	uint16_t haystack_len = ms_strlen(haystack);
		
	if(needle_len > haystack_len)
	{
		return -1;
	}
	
	for(i = 0; i < haystack_len - needle_len; i++)
	{
		if(ms_str_equal(haystack, needle_len, needle, needle_len))
		{
			return i;
		}
		
		haystack++;
	}
	
	return -1;
}

void ms_dump_array(char *array, uint16_t max_buffer, uint16_t reverse_pointer)
{
	int i;
	for(i = 0; i < max_buffer - reverse_pointer; i++)
	{
		printf("[%c]", array[reverse_pointer + i]);
	}
}

uint16_t ms_power(uint16_t base, uint16_t exponent)
{
	uint16_t ret = 1;
	int i;
	for(i = 0; i < exponent; i++)
	{
		ret *= base;
	}
	return ret;
}

uint16_t ms_array_to_number(char * array, uint16_t max_buffer, uint16_t reverse_pointer)
{
	int i;
	
	uint16_t ret = 0;
	
	for(i = 0; i < max_buffer - reverse_pointer; i++)
	{
		ret +=  (array[reverse_pointer + i] - '0') * ms_power(10, max_buffer - reverse_pointer - i - 1);
	}
	
	return ret;
}

void ms_array_slice_to_string(string_t array, uint16_t start, uint16_t end, unsigned char *ret)
{
	uint16_t i, n = 0;
	
	for(i = start; i <= end; i++)
	{
		ret[n] = array[i];
		n++;
	}
	
	ret[n] = 0;
}