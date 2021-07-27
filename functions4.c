#include "holberton.h"
/**
 *print_long_uint - a
 *@p: a
 *Return: a
 */
int print_long_uint(unsigned long int *p)
{
	unsigned long int a[10];
	unsigned long int i, m, sum;
	unsigned long int n;
	long int count;

	n = *p;
	m = 1000000000; /* (10 ^ 9) */
	a[0] = n / m;
	for (i = 1; i < 10; i++)
	{
		m /= 10;
		a[i] = (n / m) % 10;
	}
	for (i = 0, sum = 0, count = 0; i < 10; i++)
	{
		sum += a[i];
		if (sum || i == 9)
		{
			_putchar('0' + a[i]);
			count++;
		}
	}
	return (count);
}
/**
 *print_long_octa - a
 *@p: a
 *Return: a
 */
int print_long_octa(long int *p)
{
	unsigned long int num;
	unsigned long int copy;
	char *octa;
	long int i, i2 = 0, cont = 0;

	num = *p;
	if (num == 0)
		return (_putchar('0'));
	for (copy = num; copy != 0; i2++)
	{
		copy = copy / 8;
	}
	octa = malloc(i2);
	if (!octa)
		return (-1);
	for (i = i2 - 1; i >= 0; i--)
	{
		octa[i] = num % 8 + '0';
		num = num / 8;
	}
	for (i = 0; i < i2 && octa[i] == '0'; i++)
		;
	for (; i < i2; i++)
	{
		_putchar(octa[i]);
		cont++;
	}
	free(octa);
	return (cont);
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
