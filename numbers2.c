#include "main.h"

/**
 * convert - converter function, a clone of itoa
 * @numb: number
 * @base: base
 * @flags: argument flags
 * @params: paramater struct
 *
 * Return: string
 */
char *convert(long int numb, int base, int flags, params_t *params)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long num = numb;
	(void)params;

	if (!(flags & CONVERT_UNSIGNED) && numb < 0)
	{
		num = -numb;
		sign = '-';
	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[num % base];
		num = num / base;
	} while (num != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * print_unsigned - it prints unsigned integer numbers
 * @argp: the argument pointer
 * @params: the parameters struct
 *
 * Return: the bytes printed
 */
int print_unsigned(va_list argp, params_t *params)
{
	unsigned long ld;

	if (params->l_modifier)
		ld = (unsigned long)va_arg(argp, unsigned long);
	else if (params->h_modifier)
		ld = (unsigned short int)va_arg(argp, unsigned int);
	else
		ld = (unsigned int)va_arg(argp, unsigned int);
	params->unsign = 1;
	return (print_number(convert(ld, 10, CONVERT_UNSIGNED, params), params));
}



/**
 * print_address - it prints address
 * @argp: argument pointer
 * @params: the parameters struct
 *
 * Return: the bytes printed
 */
int print_address(va_list argp, params_t *params)
{
	unsigned long int num = va_arg(argp, unsigned long int);
	char *str;

	if (!num)
		return (_puts("(nil)"));

	str = convert(num, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	*--str = 'x';
	*--str = '0';
	return (print_number(str, params));
}
