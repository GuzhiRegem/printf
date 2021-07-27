#include <unistd.h>
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
 *_print_int - a
 *@num: a
 *Return: a
 */
int _print_int(int num)
{
	int out = 0;

	if (num >= 0)
	{
		if (num < 10)
		{
			_putchar(num + '0');
			return (1);
		}
		else
		{
			out = (_print_int(num / 10) + 1);
			_putchar((num % 10) + '0');
			return (out);
		}
	}
	else
	{
		_putchar('-');
		return (_print_int(num * -1) + 1);
	}
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
	return (_print_int((int)*p));
}
