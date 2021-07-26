#include <stdlib.h>
#include "holberton.h"

/**
 * print_long_lowhex - prints a hexadecimal
 *@p: o print hexadecimal
 * Return: number.
 */
int print_long_lowhex(unsigned long int *p)
{
	unsigned long int num;
	unsigned long int num2;
	int i, i2, copy, cont = 1;
	char *numhex;

	print_str("0x");
	num = *p;
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
	return (cont + 1);
}
/**
 * print_long_uphex - prints a hexadecimal
 * @p: va_list that contains the hexadecimal to print
 * Return: number of digits printed
 */
int print_long_uphex(unsigned long int *p )
{
	unsigned long int NUM;
	unsigned long int NUM2;
	int I, I2, COPY, CONT = 1;
	char *NUMHEX;

	print_str("0x");
	NUM = *p;
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
	return (CONT + 1);
}
