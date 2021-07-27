#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <stdarg.h>
/**
 *struct printer_ret - a
 *@str: a
 *@f: a
 *@type: a
 *Return: a
 */
typedef struct printers_comp
{
	char *str;
	int (*f)();
	int type;
} printer_comp;
/**
 *struct printer_ret - a
 *@f: a
 *@type: a
 *@chars: a
 *Return: a
 */
typedef struct printers_ret
{
	int (*f)();
	int type;
	int chars;
} printer;
void *choose_pointer1(va_list args, int type);
void *choose_pointer2(va_list args, int type);
int do_func(char *format, va_list args, int *ptr);
int _printf(const char *format, ...);
int _putchar(char c);
int print_char(int *p);
int print_int(int *p);
int print_str(char *p);

int print_binary(int *p);
int print_uint(unsigned int *p);
int print_octa(int *p);
int print_lowhex(unsigned int *p);
int print_uphex(unsigned int *p);
int print_unf_str(char *p);
int print_pointer(void *p);
int print_rev(char *p);
int print_ROT(char *p);
int print_long_int(long int *p);
int print_long_uint(unsigned long int *p);
int print_long_octa(long int *p);
int print_long_lowhex(unsigned long int *p);
int print_long_uphex(unsigned long int *p);
#endif
