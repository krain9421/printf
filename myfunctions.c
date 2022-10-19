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
* _print_int - prints integer
* @args: argument list
* Return: number of printed int
*/

int _print_int(va_list args)
{
	int i = va_arg(args, int);
	unsigned int num;
	int count = 0;
	char *buf;

	if (i < 0)
	{
		count++;
		write(1, "-", 1);
		num = i * -1;
	}
	else
		num = i;

	buf = convert(num, 10);
	write(1, buf, getsz(buf));
	count += getsz(buf);
	return (count);
}

/**
* _print_int_i - prints integer
* @args: argument list
* Return: number of printed int
*/

int _print_int_i(va_list args)
{
	int i = va_arg(args, int);
	unsigned int num;
	int count = 0;
	char *buf;

	if (i < 0)
	{
		count++;
		write(1, "-", 1);
		num = i * -1;
	}
	else
		num = i;

	buf = convert(i, 10);
	write(1, buf, getsz(buf));
	count += getsz(buf);
	return (count);
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

