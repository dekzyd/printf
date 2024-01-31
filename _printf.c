#include "main.h"

/**
 * _printf - it prints and inputs to the standard output
 * @format: the format string
 * Return: the total number of bytes printed
 */

int _printf(const char *format, ...)

{
	int total = 0;
	va_list argp;
	char *c, *start;

	params_t params = PARAMS_INIT;

	va_start(argp, format);

	if (!format || (format[0] == '%' && !format[1]))/* checking for NULL char */
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (c = (char *)format; *c; c++)
	{
		init_params(&params, argp);
		if (*c != '%')/*checking for the % specifier*/
		{
			total = total + _putchar(*c);
			continue;
		}
		start = c;
		c++;
		while (get_flag(c, &params)) /* while char at c is flag character */
		{
			c++; /* the next character */
		}
		c = get_width(c, &params, argp);
		c = get_precision(c, &params, argp);
		if (get_modifier(c, &params))
			c++;
		if (!get_specifier(c))
			total = total + print_from_to(start, c,
					params.l_modifier || params.h_modifier ? c - 1 : 0);
		else
			total = total + get_print_func(c, argp, &params);
	}
	_putchar(BUF_FLUSH);
	va_end(argp);
	return (total);
}
