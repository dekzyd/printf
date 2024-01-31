#include "main.h"

/**
 * get_specifier - searches for the format function
 * @str: string of the format
 * Return: the number of bytes printed
 */

int (*get_specifier(char *str))(va_list argp, params_t *params)

{
	specifier_t specifiers[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octals},
		{"u", print_unsigned},
		{"x", print_hexlow},
		{"X", print_HEXUP},
		{"p", print_address},
		{"S", print_S},
		{"r", print_revs},
		{"R", print_rot13},
		{NULL, NULL}
	};

	int c = 0;

	while (specifiers[c].specifier)
	{
		if (*str == specifiers[c].specifier[0])
		{
			return (specifiers[c].f);
		}
		c++;
	}
	return (NULL);
}

/**
 * get_print_func - gets the format function
 * @str: string of the format
 * @argp: argument pointer
 * @params: the parameters struct
 * Return: the number of bytes printed
 */

int get_print_func(char *str, va_list argp, params_t *params)
{
	int (*f)(va_list, params_t *) = get_specifier(str);

	if (f)
		return (f(argp, params));
	return (0);
}

/**
 * get_flag - finds the flag functions
 * @str: the format string
 * @params: the parameters struct
 * Return: if flag was valid
 */

int get_flag(char *str, params_t *params)

{
	int count = 0;

	switch (*str)
	{
		case '+':
			count = params->plus_flag = 1;
			break;
		case ' ':
			count = params->space_flag = 1;
			break;
		case '#':
			count = params->hashtag_flag = 1;
			break;
		case '-':
			count = params->minus_flag = 1;
			break;
		case '0':
			count = params->zero_flag = 1;
			break;
	}
	return (count);
}

/**
 * get_modifier - finds the modifier function
 * @str: string for format
 * @params: parameter structure
 * Return: if modifier is valid
 */

int get_modifier(char *str, params_t *params)
{
	int count = 0;

	switch (*str)
	{
		case 'h':
			count = params->h_modifier = 1;
			break;
		case 'l':
			count = params->l_modifier = 1;
			break;
	}
	return (count);
}

/**
 * get_width - gets the width from the format string
 * @str: the format string
 * @params: the parameters struct
 * @argp: the argument pointer
 * Return: the new pointer
 */

char *get_width(char *str, params_t *params, va_list argp)

{
	int dig = 0;

	if (*str == '*')
	{
		dig = va_arg(argp, int);
		str++;
	}
	else
	{
		while (_isdigit(*str))
			dig = dig * 10 + (*str++ - '0');
	}
	params->width = dig;
	return (str);
}
