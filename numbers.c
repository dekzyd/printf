#include "main.h"

/**
 * _isdigit - checks if a character is a digit
 * @c: the character to check
 *
 * Return: 1 if digit, 0 if not
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - returns the length of a string
 * @str: the string whose length to check
 *
 * Return: the integer length of string
 */
int _strlen(char *str)
{
	int n = 0;

	while (*str++)
		n++;
	return (n);
}

/**
 * print_number - prints a number with options
 * @str: the base number as a string
 * @params: the parameter struct
 *
 * Return: the chars printed
 */
int print_number(char *str, params_t *params)
{
	unsigned int n = _strlen(str);
	int neg = (!params->unsign && *str == '-');

	if (!params->precision && *str == '0' && !str[1])
		str = "";
	if (neg)
	{
		str++;
		n--;
	}
	if (params->precision != UINT_MAX)
		while (n++ < params->precision)
			*--str = '0';
	if (neg)
		*--str = '-';

	if (!params->minus_flag)
		return (print_number_right_shift(str, params));
	else
		return (print_number_left_shift(str, params));
}

/**
 * print_number_right_shift - prints a number with options
 * @str: the base number as a string
 * @params: the parameter struct
 *
 * Return: the chars printed
 */
int print_number_right_shift(char *str, params_t *params)
{
	unsigned int num = 0, neg, neg2, a = _strlen(str);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';
	neg = neg2 = (!params->unsign && *str == '-');
	if (neg && a < params->width && pad_char == '0' && !params->minus_flag)
		str++;
	else
		neg = 0;
	if ((params->plus_flag && !neg2) ||
		(!params->plus_flag && params->space_flag && !neg2))
		a++;
	if (neg && pad_char == '0')
		num = num + _putchar('-');
	if (params->plus_flag && !neg2 && pad_char == '0' && !params->unsign)
		num = num + _putchar('+');
	else if (!params->plus_flag && params->space_flag && !neg2 &&
		!params->unsign && params->zero_flag)
		num = num + _putchar(' ');
	while (a++ < params->width)
		num = num + _putchar(pad_char);
	if (neg && pad_char == ' ')
		num = num + _putchar('-');
	if (params->plus_flag && !neg2 && pad_char == ' ' && !params->unsign)
		num = num + _putchar('+');
	else if (!params->plus_flag && params->space_flag && !neg2 &&
		!params->unsign && !params->zero_flag)
		num = num + _putchar(' ');
	num = num + _puts(str);
	return (num);
}

/**
 * print_number_left_shift - prints a number with options
 * @str: the base number as a string
 * @params: the parameter struct
 *
 * Return: the chars printed
 */
int print_number_left_shift(char *str, params_t *params)
{
	unsigned int num = 0, neg, neg2, a = _strlen(str);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';
	neg = neg2 = (!params->unsign && *str == '-');
	if (neg && a < params->width && pad_char == '0' && !params->minus_flag)
		str++;
	else
		neg = 0;

	if (params->plus_flag && !neg2 && !params->unsign)
		num = num + _putchar('+'), a++;
	else if (params->space_flag && !neg2 && !params->unsign)
		num = num + _putchar(' '), a++;
	num = num + _puts(str);
	while (a++ < params->width)
		num = num + _putchar(pad_char);
	return (num);
}
