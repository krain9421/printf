#include "main.h"
#include <stdio.h>

/**
* _print_char - prints character
* @args: argument list, va_list
*
* Return: number of printed chars
*/

int _print_char(va_list args)
{
	char c = va_arg(args, int);

	write(1, &c, 1);
	return (1);
}

/**
* _print_string - prints bytes of a string
* excluding the null byte
* @args: argument list
*
* Return: number of printed chars
*/

int _print_string(va_list args)
{
	int count = 0;
	char *sbuf = va_arg(args, char *);

	if (sbuf == NULL)
		sbuf = "(null)";

	write(1, sbuf, getsz(sbuf));
	count += getsz(sbuf);
	return (count);
}

/**
* _print_mod - prints "%"
* @args: argument list
*
* Return: number of printed chars
*/

int _print_mod(va_list args)
{
	args = args;
	write(1, "%", 1);
	return (1);
}

