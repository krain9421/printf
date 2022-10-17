#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

/**
* struct pr - struct for printing
* @ch: character to indicate type of argument
* @f: function to be called if character fits
*/

typedef struct pr
{
	char ch;
	int (*f)(va_list);
} pr_t;

int _printf(const char *format, ...);
int getsz(char *s);
int _print_char(va_list);
int _print_string(va_list);
int _print_mod(va_list);
int (*get_pr_func(char c))(va_list);
#endif

