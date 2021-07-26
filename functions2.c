#include "holberton.h"
#include <stdlib.h>


/**
 * print_binary - function to print binary
 * @p: list being passed
 * Return: updated count return
 */
int print_binary(int *p)
{
	int count = 0, i;
	int *arr;
	unsigned int n;
	n = *p;
	unsigned int tmp = n;

	while (n / 2 != 0)
	{
		n /= 2;
		count++;
	}
	count++;
	arr = malloc(count * sizeof(int));
	if (arr == NULL)
	{
		free(arr);
		return (0);
	}
	for (i = 0; i < count; i++)
	{
		arr[i] = tmp % 2;
		tmp /= 2;
	}
	for (i = count - 1; i >= 0; i--)
	{
		_putchar(arr[i] + '0');
	}
	free(arr);
	return (count);
}
/**
 * print_uint - prints an unsigned in in decimal notation
 * @p: unsigned int to print
 *
 * Return: number of digits printed
 */
int print_uint(unsigned int *p)
{
	unsigned int a[10];
	unsigned int i, m, sum;
	unsigned int n;
	int count;

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
 * print_octa - prints a hexadecimal
 * @p:  print hexadecimal
 * Return: number.
 */
int print_octa(int *p)
{
	unsigned int num;
	num = *p;
	unsigned int copy;
	char *octa;
	int i, i2 = 0, cont = 0;

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
 * print_lowhex - prints a hexadecimal
 *@p: o print hexadecimal
 * Return: number.
 */
int print_lowhex(int *p)
{
	unsigned int num;
	num = *p;
	unsigned int num2;
	int i, i2, copy, cont = 0;
	char *numhex;

	if (num == 0)
		return (_putchar('0'));
	for (num2 = num; num2 != 0; cont++)
	{
		num2 = num2 / 16;
	}
	numhex = malloc(cont);
	for (i = 0; num != 0; i++)
	{
		copy = num % 16;
		if (copy < 10)
			numhex[i] = copy + '0';
		else
			numhex[i] = copy - 10  + 'a';
		num = num / 16;
	}
	for (i2 = i - 1; i2 >= 0; i2--)
		_putchar(numhex[i2]);
	free(numhex);
	return (cont);
}
/**
 * print_uphex - prints a hexadecimal
 * @p: va_list that contains the hexadecimal to print
 * Return: number of digits printed
 */
int print_uphex(int *p )
{
	unsigned int NUM;
	NUM = *p;
	unsigned int NUM2;
	int I, I2, COPY, CONT = 0;
	char *NUMHEX;

	if (NUM == 0)
		return (_putchar('0'));
	for (NUM2 = NUM; NUM2 != 0; CONT++)
	{
		NUM2 = NUM2 / 16;
	}
	NUMHEX = malloc(CONT);
	for (I = 0; NUM != 0; I++)
	{
		COPY = NUM % 16;
		if (COPY < 10)
			NUMHEX[I] = COPY + '0';
		else
			NUMHEX[I] = COPY - 10 + 'A';
		NUM = NUM / 16;
	}
	for (I2 = I - 1; I2 >= 0; I2--)
		_putchar(NUMHEX[I2]);
	free(NUMHEX);
	return (CONT);
}
