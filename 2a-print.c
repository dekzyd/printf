#include "main.h"

/**
 * print_char - it prints characters
 * @argp: argument pointer
 * @params: the parameters struct
 *
 * Return: the total number of chars printed
 */
int print_char(va_list argp, params_t *params)
{
	char pad_char = ' ';
	unsigned int pads = 1, total = 0, ch = va_arg(argp, int);

	if (params->minus_flag)
		total = total + _putchar(ch);
	while (pads++ < params->width)
		total = total + _putchar(pad_char);
	if (!params->minus_flag)
		total = total + _putchar(ch);
	return (total);
}

/**
 * print_string - it prints strings
 * @argp: argument pointer
 * @params: the parameters struct
 *
 * Return: the total number of chars printed
 */
int print_string(va_list argp, params_t *params)
{
	char *str = va_arg(argp, char *), pad_char = ' ';
	unsigned int pads = 0, total = 0, a = 0, b;

	(void)params;
	switch ((int)(!str))
		case 1:
			str = NULL_STRING;

	b = pads = _strlen(str);
	if (params->precision < pads)
		b = pads = params->precision;

	if (params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (a = 0; a < pads; a++)
				total = total + _putchar(*str++);
		else
			total = total + _puts(str);
	}
	while (b++ < params->width)
		total = total + _putchar(pad_char);
	if (!params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (a = 0; a < pads; a++)
				total = total + _putchar(*str++);
		else
			total = total + _puts(str);
	}
	return (total);
}

/**
 * print_int - prints integer
 * @argp: argument pointer
 * @params: the parameters struct
 *
 * Return: the total number of chars printed
 */
int print_int(va_list argp, params_t *params)
{
	long l;

	if (params->l_modifier)
		l = va_arg(argp, long);
	else if (params->h_modifier)
		l = (short int)va_arg(argp, int);
	else
		l = (int)va_arg(argp, int);
	return (print_number(convert(l, 10, 0, params), params));
}

/**
 * print_percent -it prints string
 * @argp: argument pointer
 * @params: the parameters struct
 *
 * Return: the total number of chars printed
 */
int print_percent(va_list argp, params_t *params)
{
	(void)argp;
	(void)params;
	return (_putchar('%'));
}

/**
 * print_S - the custom format specifier
 * @argp: argument pointer
 * @params: the parameters struct
 *
 * Return: the total number of chars printed
 */
int print_S(va_list argp, params_t *params)
{
	char *str = va_arg(argp, char *);
	char *hex;
	int total = 0;

	if ((int)(!str))
		return (_puts(NULL_STRING));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			total = total + _putchar('\\');
			total = total + _putchar('x');
			hex = convert(*str, 16, 0, params);
			if (!hex[1])
				total = total + _putchar('0');
			total = total + _puts(hex);
		}
		else
		{
			total = total + _putchar(*str);
		}
	}
	return (total);
}
