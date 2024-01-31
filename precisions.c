#include "main.h"

/**
 * get_precision - fetches the precision from the format string
 * @str: the format string
 * @params: the parameters struct
 * @argp: the argument pointer
 * Return: new pointer
*/

char *get_precision(char *str, params_t *params, va_list argp)
{
	int dig = 0;

	if (*str != '.')
		return (str);
	str++;
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
	params->precision = dig;
	return (str);
}
