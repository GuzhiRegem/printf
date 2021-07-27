#include "holberton.h"
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
/**
 *_putchar - a
 *@c: a
 *Return: a
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 *print_str - a
 *@p: a
 *Return: a
 */
int print_str(char *p)
{
	char *str;

	str = p;
	if (!str[0])
		return (0);
	_putchar(str[0]);
	return (print_str(str + 1) + 1);
	return (0);
}
/**
 *print_char - a
 *@p: a
 *Return: a
 */
int print_char(int *p)
{
	return (_putchar((int)*p));
}
/**
 *print_int - a
 *@p: a
 *Return: a
 */
int print_int(int *p)
{
	if ((*p >= INT_MIN) && (*p <= INT_MAX))
		return (_print_long_int((long int)*p));
	return (0);
}
