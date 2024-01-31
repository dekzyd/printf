#include "main.h"

/**
 * print_from_to - prints a range of char addresses
 * @start: the start address
 * @stop: the stop address
 * @expect: the expect address
 *
 * Return: the total number of bytes printed
 */
int print_from_to(char *start, char *stop, char *expect)
{
	int total = 0;

	while (start <= stop)
	{
		if (start != expect)
			total = total + _putchar(*start);
		start++;
	}
	return (total);
}

/**
 * print_revs - it prints the string in reverse
 * @argp: the string
 * @params: the parameters struct
 *
 * Return: the total number of bytes printed
 */
int print_revs(va_list argp, params_t *params)
{
	int len, total = 0;
	char *str = va_arg(argp, char *);
	(void)params;

	if (str)
	{
		for (len = 0; *str; str++)
			len++;
		str--;
		for (; len > 0; len--, str--)
			total = total + _putchar(*str);
	}
	return (total);
}

/**
 * print_rot13 - it prints string in rot13
 * @argp: the string
 * @params: the parameters struct
 *
 * Return: the total number of bytes printed
 */
int print_rot13(va_list argp, params_t *params)
{
	int count, index;
	int amount = 0;
	char arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(argp, char *);
	(void)params;

	count = 0;
	index = 0;
	while (a[count])
	{
		if ((a[count] >= 'A' && a[count] <= 'Z')
		    || (a[count] >= 'a' && a[count] <= 'z'))
		{
			index = a[count] - 65;
			amount = amount + _putchar(arr[index]);
		}
		else
			amount = amount + _putchar(a[count]);
		count++;
	}
	return (amount);
}
