#ifndef _PRINTF_H_
#define _PRINTF_H_

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define FIELD_BUF_SIZE 50

#define NULL_STRING "(null)"

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/**
 * struct parameters - parameters struct
 *
 * @unsign: flag if unsigned value
 *
 * @plus_flag: on if plus_flag specified
 * @space_flag: on if hashtag_flag specified
 * @hashtag_flag: on if _flag specified
 * @zero_flag: on if _flag specified
 * @minus_flag: on if _flag specified
 *
 * @width: field width specified
 * @precision: field precision specified
 *
 * @h_modifier: on if h_modifier is specified
 * @l_modifier: on if l_modifier is specified
 *
 */

typedef struct parameters
{
	unsigned int unsign			: 1;

	unsigned int plus_flag		: 1;
	unsigned int space_flag		: 1;
	unsigned int hashtag_flag	: 1;
	unsigned int zero_flag		: 1;
	unsigned int minus_flag		: 1;

	unsigned int width;
	unsigned int precision;

	unsigned int h_modifier		: 1;
	unsigned int l_modifier		: 1;
} params_t;

/**
 * struct specifier - Struct token
 *
 * @specifier: format token
 * @f: The function associated
 */
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_t *);
} specifier_t;

/* the _put.c modules */
int _puts(char *string);
int _putchar(int c);

/* the print_functions.c modules */
int print_char(va_list argp, params_t *params);
int print_int(va_list argp, params_t *params);
int print_string(va_list argp, params_t *params);
int print_percent(va_list argp, params_t *params);
int print_S(va_list argp, params_t *params);

/* the number.c modules */
char *convert(long int num, int base, int flags, params_t *params);
int print_unsigned(va_list argp, params_t *params);
int print_address(va_list argp, params_t *params);

/* the specifier.c modules */
int (*get_specifier(char *str))(va_list argp, params_t *params);
int get_print_func(char *str, va_list argp, params_t *params);
int get_flag(char *str, params_t *params);
int get_modifier(char *str, params_t *params);
char *get_width(char *str, params_t *params, va_list argp);

/* the convert_number.c modules */
int print_hexlow(va_list argp, params_t *params);
int print_HEXUP(va_list argp, params_t *params);
int print_binary(va_list argp, params_t *params);
int print_octals(va_list argp, params_t *params);

/* the simple_printers.c modules */
int print_from_to(char *start, char *stop, char *expect);
int print_revs(va_list argp, params_t *params);
int print_rot13(va_list argp, params_t *params);

/* the print_number.c modules */
int _isdigit(int c);
int _strlen(char *str);
int print_number(char *str, params_t *params);
int print_number_right_shift(char *str, params_t *params);
int print_number_left_shift(char *str, params_t *params);

/* the params.c module */
void init_params(params_t *params, va_list argp);

/* the string_fields.c module */
char *get_precision(char *str, params_t *params, va_list argp);

/* the _prinf.c module */
int _printf(const char *format, ...);

#endif /*_MAIN_H_*/#
