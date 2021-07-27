#include "holberton.h"
/**
 *print_long_uint - a
 *@p: a
 *Return: a
 */
int print_long_uint(unsigned long int *p)
{
	if (*p > 0)
		_putchar('a');
	return (0);
}
/**
 *print_long_octa - a
 *@p: a
 *Return: a
 */
int print_long_octa(long int *p)
{
	if (*p > 0)
		_putchar('a');
	return (0);
}
/**
 *_print_long_int - a
 *@num: a
 *Return: a
 */
int _print_long_int(long int num)
{
	long int out = 0;

	if (num >= 0)
	{
		if (num < 10)
		{
			_putchar(num + '0');
			return (1);
		}
		else
		{
			out = (_print_long_int(num / 10) + 1);
			_putchar((num % 10) + '0');
			return (out);
		}
	}
	else
	{
		_putchar('-');
		return (_print_long_int(num * -1) + 1);
	}
}
