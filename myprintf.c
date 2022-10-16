#include "main.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/**
* getsz - function returns the bytes in a string
* @s: The string to be checked
*
* Return: size of string in bytes
* NULL if string is not valid
*/

int getsz(char *s)
{
	int i = 0;

	if (s == NULL)
	{ return (i); }
	else
	{
		while (s[i])
		{
			i++;
		}
		return (i);
	}
}

/**
* _printf - function that produces output
* according to a format
* @format: character string
*
* Return: the number of characters printed
*/

int _printf(const char *format, ...)
{
	int i = 0; /* character index */
	int count = 0;
	char *str;
	va_list args;

	if (format != NULL)
	{
		va_start(args, format);
		while (format[i] != '\0')
		{
			while (format[i] != '%' && format[i] != '\0')
			{
				write(1, format + i++, 1);
				count++;
			}
			if (format[i] == '\0')
			{ break; }
			i++;
			switch (format[i])
			{
				case 'c':
					str[0] = va_arg(args, int);
					write(1, str, 1);
					break;
				case 's':
					str = va_arg(args, char *);
					write(1, str, getsz(str));
					break;
				case '%':
					write(1, "%", 1);
					break;
			}
			count++;
			i++;
		}
	}
	va_end(args);
	return (count);
}
