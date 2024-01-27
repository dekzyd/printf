#include <stdlib.h>
#include <stdio.h>

/**
 * _itoa- converts integer to string
 * @n: integer to be converted
 *
 * Return: pointer to string
 */
char *_itoa(int n)
{
	char *s;

	s = malloc(sizeof(int));
	sprintf(s, "%d", n);
	return (s);
}
