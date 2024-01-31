#include "main.h"

/**
 * _puts - prints a string with newline
 * @string: the string to print
 *
 * Return: (string - c)
 */
int _puts(char *string)
{
	char *c = string;

	while (*string)
		_putchar(*string++);
	return (string - c);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and error is set accordingly.
 */
int _putchar(int c)
{
	static int a;
	static char buf[OUTPUT_BUF_SIZE];

	if (c == BUF_FLUSH || a >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, a);
		a = 0;
	}
	if (c != BUF_FLUSH)
		buf[a++] = c;
	return (1);
}
