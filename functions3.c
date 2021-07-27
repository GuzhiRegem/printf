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
	return (print_long_lowhex(point));
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
	if (!str)
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
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = p;
	if (!str)
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
	return (_print_long_int((long int)*p));
}
