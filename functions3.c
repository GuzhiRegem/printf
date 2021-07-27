#include "holberton.h"
/**
 *print_unf_str - a
 *@p: a
 *Return: a
 */
int print_unf_str(char *p)
{
	_putchar(p[0]);
	return (p[0]);
}
/**
 *print_pointer - a
 *@p: a
 *Return: a
 */
int print_pointer(void *p)
{
	unsigned long int ptr;
	unsigned long int *point;

	ptr = (unsigned long int)p;
	point = &ptr;
	print_long_lowhex(point);
	return (0);
}
/**
 *print_rev - a
 *@p: a
 *Return: a
 */
int print_rev(char *p)
{
	
	char *str;
	int i, count = 0;

	str = p;
	if (str == NULL)
		str = ")llun(";
	for (i = 0; str[i]; i++)
		;
	for (i -= 1; i >= 0; i--)
	{
		_putchar(str[i]);
		count++;
	}
	return (count);
}
/**
 *print_ROT - a
 *@p: a
 *Return: a
 */
int print_ROT(char *p)
{
	char *str;
	str = p;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(R, char *);
	if (str == NULL)
		str = "(ahyy)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				_putchar(out[j]);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			_putchar(str[i]);
			count++;
		}
	}
	return (count);
}
/**
 *print_long_int - a
 *@p: a
 *Return: a
 */
int print_long_int(long int *p)
{
	long int out = 0;
	long int num;
	num = *p;

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
