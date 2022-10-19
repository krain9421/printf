#include "main.h"

/**
* convert - converts a number to a specified base
* @num: number to convert
* @base: base for number to be converted to
*
* Return: number in string format
*/

char *convert(int num, int base)
{
	static const char digits[] = "0123456789ABCDEF";
	char buffer[50];
	char *ptr;
	char pfx;

	ptr = &buffer[49];
	*ptr = '\0';

	if (num < 0)
	{
		num *= -1;
		pfx = '-';
	}

	do {
		*--ptr = digits[num % base];
		num /= base;
	} while (num != 0);

	if (pfx)
		*--ptr = pfx;

	return (ptr);
}

