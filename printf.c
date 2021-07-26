#include "holberton.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
typedef struct printers_comp
{
	char *str;
	int (*f)();
	int type;
} printer_comp;
typedef struct printers_ret
{
	int (*f)();
	int type;
	int chars;
} printer;
int cmpr(printer_comp com, char *str)
{
	int out = 0;
	int i;

	for (i = 0; com.str[i]; i++)
	{
		if (com.str[i] != str[i])
			out = 1;
	}
	out += (i - 1) * 10;
	return (out);
}
printer get_func(char *s)
{
	int i, comp;
	printer out = {NULL, 0};
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
	printer_comp cases[] = {
		{"c", print_char, 0},
		{"s", print_str, 1},
		{"d", print_int, 0},
		{"i", print_int, 0},
		{"u", print_uint, 2},
		{"o", print_octa, 0},
		{"b", print_binary, 0},
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
		{"ld", print_int, 0},
		{"li", print_int, 0},
		{"lu", print_uint, 0},
		{"lo", print_octa, 0},
		{"lx", print_lowhex, 0},
		{"lX", print_uphex, 0}
	};
	for (i = 0; i < 20; i++)
	{
		test = cases[i];
		comp = cmpr(test, s);
		if (comp % 10)
		{
			out.f = test.f;
			out.type = test.type;
			out.chars = comp / 10;
			return (out);
		}
	}
	out.f = NULL;
	out.type = 0;
	out.chars = 0;
	return (out);

}
void *choose_pointer(va_list args, int type)
{
	int *in;
	unsigned int *ui;
	long int *li;
	unsigned long int *uli;
	switch (type)
	{
	case 0:
		in = malloc(sizeof(int));
		if (in)
		{
			*in = va_arg(args, int);
			return(in);
		}
		break;
	case 1:
		return (va_arg(args, char *));
		break;
	case 2:
		ui = malloc(sizeof(unsigned int));
		if (ui)
		{
			*in = va_arg(args, unsigned int);
			return (ui);
		}
		break;
	case 3:
		return (va_arg(args, void *));
		break;
	case 4:
		li = malloc(sizeof(long int));
		if (li)
		{
			*li = va_arg(args, long int);
			return (li);
		}
		break;
	case 5:
		uli = malloc(sizeof(unsigned long int));
		if (uli)
		{
			*uli = va_arg(args, unsigned long int);
			return (uli);
		}
		break;
	}
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
				func_cmp = get_func((char *)format + i);
				if (func_cmp.f)
				{
					point = choose_pointer(args,
							       func_cmp.type);
					if (point)
					{
						out += func_cmp.f(point);
						free(point);
						i += func_cmp.chars;
					}
				}
			}
		}
	}
	else
	{
		out += print_str("(nil)");
	}
	va_end(args);
	return (out);
}
