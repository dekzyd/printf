#include <unistd.h>

/**
 * _putchar - displays a single char to stdout.
 * @c: character to be displayed.
 *
 * Return: char
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
