#include "holberton.h"

int print_unf_str(char *p)
{
	_putchar(p[0]);
	return (p[0]);
}
int print_pointer(void *p)
{
	unsigned long int ptr;
	unsigned long int *point;

	ptr = (unsigned long int)p;
	point = &ptr;
	print_long_lowhex(point);
	return (0);
}
int print_rev(char *p)
{
	_putchar(p[0]);
	return (p[0]);
}
int print_ROT(char *p)
{
	return (p[0]);
}
int print_long_int(long int *p)
{
	if (*p < 0)
		_putchar('a');
	return (0);
}
