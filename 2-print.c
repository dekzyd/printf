#include "main.h"

/**
 * print_hexlow - it prints unsigned hex numbers in lowercase
 * @argp: the argument pointer
 * @params: the parameters struct
 *
 * Return: the bytes printed
 */
int print_hexlow(va_list argp, params_t *params)
{
	unsigned long l;
	int a = 0;
	char *str;

	if (params->l_modifier)
		l = (unsigned long)va_arg(argp, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(argp, unsigned int);
	else
		l = (unsigned int)va_arg(argp, unsigned int);

	str = convert(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	if (params->hashtag_flag && l)
	{
		*--str = 'x';
		*--str = '0';
	}
	params->unsign = 1;
	return (a = a + print_number(str, params));
}

/**
 * print_HEXUP - it prints the unsigned hex numbers in uppercase
 * @argp: the argument pointer
 * @params: the parameters struct
 *
 * Return: the bytes printed
 */
int print_HEXUP(va_list argp, params_t *params)
{
	unsigned long l;
	int a = 0;
	char *str;

	if (params->l_modifier)
		l = (unsigned long)va_arg(argp, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(argp, unsigned int);
	else
		l = (unsigned int)va_arg(argp, unsigned int);

	str = convert(l, 16, CONVERT_UNSIGNED, params);
	if (params->hashtag_flag && l)
	{
		*--str = 'X';
		*--str = '0';
	}
	params->unsign = 1;
	return (a = a + print_number(str, params));
}
/**
 * print_binary - it prints unsigned binary numbers
 * @argp: the argument pointer
 * @params: the parameters struct
 *
 * Return: the bytes printed
 */
int print_binary(va_list argp, params_t *params)
{
	unsigned int n = va_arg(argp, unsigned int);
	char *str = convert(n, 2, CONVERT_UNSIGNED, params);
	int a = 0;

	if (params->hashtag_flag && n)
		*--str = '0';
	params->unsign = 1;
	return (a = a + print_number(str, params));
}

/**
 * print_octals - it prints unsigned octal numbers
 * @argp: the argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int print_octals(va_list argp, params_t *params)
{
	unsigned long l;
	int a = 0;
	char *str;

	if (params->l_modifier)
		l = (unsigned long)va_arg(argp, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(argp, unsigned int);
	else
		l = (unsigned int)va_arg(argp, unsigned int);
	str = convert(l, 8, CONVERT_UNSIGNED, params);

	if (params->hashtag_flag && l)
		*--str = '0';
	params->unsign = 1;
	return (a = a + print_number(str, params));
}
