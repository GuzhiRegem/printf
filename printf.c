#include "holberton.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

/**
 *cmpr - a
 *@com: a
 *@str: a
 *Return: a
 */
int cmpr(char *com, char *str)
{
	int out = 1;
	int i;

	for (i = 0; com[i]; i++)
	{
		if (com[i] != str[i])
		{
			out = 0;
			break;
		}
	}
	out += (i - 1) * 10;
	return (out);
}
/**
 *get_case - a
 *@i: A
 *Return: a
 */
printer_comp get_case(int i)
{
	printer_comp cases[] = {
		{"c", print_char, 0},
		{"s", print_str, 1},
		{"d", print_int, 0},
		{"i", print_int, 0},
		{"u", print_uint, 2},
		{"o", print_octa, 0},
		{"b", print_binary, 0},
		{"x", print_lowhex, 2},
		{"X", print_uphex, 2},
		{"S", print_unf_str, 1},
		{"p", print_pointer, 3},
		{"r", print_rev, 1},
		{"R", print_ROT, 1},
		{"ld", print_long_int, 4},
		{"li", print_long_int, 4},
		{"lu", print_long_uint, 5},
		{"lo", print_long_octa, 4},
		{"lx", print_long_lowhex, 5},
		{"lX", print_long_uphex, 5},
		{"ld", print_int, 0},
		{"li", print_int, 0},
		{"lu", print_uint, 0},
		{"lo", print_octa, 0},
		{"lx", print_lowhex, 0},
		{"lX", print_uphex, 0}
	};
	return (cases[i]);
}
/**
 *get_func - a
 *@s: a
 *Return: a
 */
printer get_func(char *s)
{
	int i = 0;
	int comp, bool;
	printer out;
	printer_comp test;

	/**
	 *type numbers:
	 *0 - int
	 *1 - string
	 *2 - unsigned int
	 *3 - pointer
	 *4 - long int
	 *5 - unsigned long int
	 */
	i = 0;
	out.f = NULL;
	out.type = 0;
	out.chars = 0;
	while (i < 25)
	{
		test = get_case(i);
		comp = cmpr(test.str, s);
		bool = comp % 10;
		if (bool)
		{
			out.f = test.f;
			out.type = test.type;
			out.chars = comp / 10;
			break;
		}
		i++;
	}
	return (out);
}
/**
 *_printf - printf
 *@format: a
 *Return: a
 */
int _printf(const char *format, ...)
{
	int i, out = 0;
	int incomm = 0;
	va_list args;
	int *ptr = &i;

	if (!format)
	{
		out += print_str("(nil)");
		return (out);
	}
	va_start(args, format);
	for (i = 0; format[i]; i++)
	{
		if (!incomm)
		{
			if (format[i] == '%')
				incomm = 1;
			else
				out += _putchar(format[i]);
		}
		else
		{
			if (format[i] == '%')
				out += _putchar('%');
			else
				out += do_func((char *)format + i, args, ptr);
			incomm = 0;
		}
	}
	va_end(args);
	return (out);
}
/**
 *do_func - a
 *@format: a
 *@args: a
 *@ptr: a
 *Return: a
 */
int do_func(char *format, va_list args, int *ptr)
{
	int out = 0;
	printer func_cmp;
	void *point;

	func_cmp = get_func(format);
	if (func_cmp.f)
	{
		point = choose_pointer1(args,
					func_cmp.type);
		if (!point)
			point = choose_pointer2(args,
						func_cmp.type);
		if (point)
		{
			out += func_cmp.f(point);
			if ((func_cmp.type != 1) &&
			    (func_cmp.type != 3))
				free(point);
			*ptr += func_cmp.chars;
		}
	}
	return (out);
}
