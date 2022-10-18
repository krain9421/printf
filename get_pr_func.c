#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
* get_pr_func - selects the correct function to perform
* @c: character passed
*
* Return: pointer to the function that
* corresponds to the character
*/

int (*get_pr_func(char c))(va_list)
{
	pr_t prs[] = {
		{'c', _print_char},
		{'s', _print_string},
		{'%', _print_mod},
		{'d', _print_int},
		{'i', _print_int_i},
		{'\0', NULL}
	};
	int i = 0;

	while (prs[i].ch != '\0')
	{
		if (c == prs[i].ch)
		{
			return (prs[i].f);
		}
		i++;
	}
	return (NULL);
}

