#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * _printf- prints formatted strings and handle various format specifiers
 * @format: string with directives or format specifiers
 *
 * Return: length of format string
 */
int _printf(const char *format, ...)
{
	int str_len, i;
	char *str;
	char *dec;
	va_list argt;

	va_start(argt, format);
	str_len = 0;
	if (format != NULL)
	{
		while (*format != '\0')
		{
			if (*format == '\0')
				break;
			if (*format == '%')
				format++;
			while (*format != '\0' && *format != '%')
			{
				putchar(*format);
				str_len++;
				format++;
			}

			switch (*format)
			{
				case '%':
					putchar('%');
					break;
				case 'c':
					i = va_arg(argt, int);
					putchar(i);
					break;
				case 's':
					str = va_arg(argt, char *);
					while (*str != '\0')
					{
						putchar(*str);
						str_len++;
						str++;
					}
					str_len--;
					break;
				case 'd':
					dec = _itoa(va_arg(argt, int));
					while (*dec != '\0')
					{
						putchar(*dec);
						str_len++;
						dec++;
					}
					str_len--;
					break;
				case 'i':
					dec = _itoa(va_arg(argt, int));
					while (*dec != '\0')
					{
						putchar(*dec);
						str_len++;
						dec++;
					}
					str_len--;
					break;
				default:
					putchar('%');
					putchar(*format);
					str_len++;
			}
			format++;
			str_len++;
		}
	}
	va_end(argt);
	return (str_len);
}
