#include "main.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/**
* getsz - function returns the number
* of bytes in a string excluding the null byte
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
	int i = 0, count = 0;
	int (*fn)(va_list);
	va_list args;

	if (format != NULL)
	{	va_start(args, format);
		for (; format[i]; i++)
		{
			if (format[i] != '%')
			{
				write(1, format + i, 1);
				count++;
			}
			else if (format[i] == '%')
			{
				i++;
				fn = get_pr_func(format[i]);
				if (fn == NULL)
				{}
				else
				{ count += fn(args); }
				if (format[i] == '\0')
					return (-1);
				if (format[i] != '\0' && fn == NULL)
				{
					write(1, format + i - 1, 1);
					write(1, format + i, 1);
					count += 2;
				}

			}
		}
		va_end(args);
		return (count);
	}
	return (-1);
}


