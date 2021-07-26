#include "holberton.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
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
	i = 0;
	out.f = NULL;
	out.type = 0;
	out.chars = 0;
        while (i < 25)
	{
		test = cases[i];
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
void *choose_pointer(va_list args, int type)
{
	int *in;
	unsigned int *ui;
	long int *li;
	unsigned long int *uli;
	char *st;
	void *ptr;
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
		st = malloc(sizeof(char *));
		if (st)
		{
			st = va_arg(args, char *);
			return (st);
		}
		break;
	case 2:
		ui = malloc(sizeof(unsigned int));
		if (ui)
		{
			*ui = va_arg(args, unsigned int);
			return (ui);
		}
		break;
	case 3:
	        ptr = malloc(sizeof(void *));
		if (ptr)
		{
			ptr = va_arg(args, void *);
			return (ptr);
		}
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
	return (NULL);
}
int _printf(const char *format, ...)
{
	int i, out = 0;
	int incomm = 0;
	va_list args;
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
						if ((func_cmp.type != 1) &&
						    (func_cmp.type != 3))
							free(point);
						i += func_cmp.chars;
					}
				}
				incomm = 0;
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
