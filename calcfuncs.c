#include "main.h"
#include <stdio.h>

/**
* convert - converts a number to a specified base
* @num: number to convert
* @base: base for number to be converted to
*
* Return: number in string format.
*/

char *convert(unsigned int num, int base)
{
	static const char digits[] = "0123456789ABCDEF";
	static char buffer[50];
	char *ptr;

	ptr = &buffer[49];
	*ptr = '\0';

	do {
		*--ptr = digits[num % base];
		num /= base;
	} while (num != 0);

	return (ptr);
}

