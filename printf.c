#include "holberton.h"
#include <stdarg.h>
#include <stddef.h>
typedef struct printers_comp
{
	char *str;
	int (*f)(void *);
	int type;
} printer;
typedef struct printers_ret
{
	int (*f)(void *);
	int type;
} printer_comp;
int cmpr(printer_comp com, char *str)
{
	int out = 1;
	int i;

	for (i = 0; com.str[i]; i++)
	{
		if (com.str[i] != str[i])
			out = 0;
	}
	return (out);
}
printer get_func(char *s)
{
	int i, comp;

	/**
	 *type numbers:
	 *0 - int
	 *1 - string
	 *2 - unsigned int
	 *3 - pointer
	 *4 - long int
	 *5 - unsigned long int
	 *6 - short int
	 *7 - unsigned short int
	 */
	printer cases[] = {
		{"c", _putchar, 0},
		{"s", print_str, 1},
		{"d", print_int, 0},
		{"i", print_int, 0},
		{"u", print_uint, 2},
		{"o", print_octa, 0},
		{"x", print_lowhex, 0},
		{"X", print_uphex, 0},
		{"S", print_unf_str, 1},
		{"p", print_pointer, 3},
		{"r", print_rev, 1},
		{"R", print_ROT, 1},
		{"ld", print_long_int, 4},
		{"li", print_long_int, 4},
		{"lu", print_long_uint, 5},
		{"lo", print_long_octa, 4},
		{"lx", print_long_lowhex, 4},
		{"lX", print_long_uphex, 4},
		{"ld", print_short_int, 6},
		{"li", print_short_int, 6},
		{"lu", print_short_uint, 7},
		{"lo", print_short_octa, 6},
		{"lx", print_short_lowhex, 6},
		{"lX", print_short_uphex, 6}};
	for (i = 0; i < 26; i++)
	{
		comp = cmpr(cases[i], s);
		if (comp)
			return ({cases[i].f, cases[i].type});
	}
	return ({NULL, 0});

}
void *choose_pointer(va_list args, int type)
{
	void *out;
	switch (type)
	{
	case 0:
		*out = va_arg(args, int);
		break;
	case 1:
		*out = va_arg(args, char *);
		break;
	case 2:
		*out = va_arg(args, unsigned int);
		break;
	case 3:
		*out = va_arg(args, void *);
		break;
	case 4:
		*out = va_arg(args, long int);
		break;
	case 5:
		*out = va_arg(args, unsigned long int);
		break;
	case 6:
		*out = va_arg(args, short int);
		break;
	case 7:
		*out = va_arg(args, unsigned short int);
		break;
	}
	return (out);
}
int _printf(const char *format, ...)
{
	int i, out = 0;
	int incomm = 0;
	va_list args;
	int (*func)(void *);
	printer func_cmp;
	void *point;
	va_start(args, format);
        if (format)
	{
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
				func_cmp = get_func(format + i);
				if (func_cmp.f)
				{
					point = choose_pointer(args, func_cmp.type);
					out += func_cmp.f(point);
				}
			}
		}
	}
	else
		out += print_str("(nil)");
	va_end(args);
	return (out);
}
