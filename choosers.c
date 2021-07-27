#include <stdarg.h>
#include <stdlib.h>
/**
 *choose_pointer1 - a
 *@args: a
 *@type: a
 *Return: a
 */
void *choose_pointer1(va_list args, int type)
{
	int *in;
	char *st;
	unsigned int *ui;

	switch (type)
	{
	case 0:
		in = malloc(sizeof(int));
		if (in)
		{
			*in = va_arg(args, int);
			return (in);
		}
		break;
	case 1:
		st = malloc(sizeof(char *));
		if (st)
		{
			st = va_arg(args, char *);
			return (st);
		}
		break;
	case 2:
		ui = malloc(sizeof(unsigned int));
		if (ui)
		{
			*ui = va_arg(args, unsigned int);
			return (ui);
		}
		break;
	}
	return (NULL);
}
/**
 *choose_pointer2 - a
 *@args: a
 *@type: a
 *Return: a
 */
void *choose_pointer2(va_list args, int type)
{
	unsigned long int *uli;
	long int *li;
	void *ptr;

	switch (type)
	{
	case 3:
		ptr = malloc(sizeof(void *));
		if (ptr)
		{
			ptr = va_arg(args, void *);
			return (ptr);
		}
		break;
	case 4:
		li = malloc(sizeof(long int));
		if (li)
		{
			*li = va_arg(args, long int);
			return (li);
		}
		break;
	case 5:
		uli = malloc(sizeof(unsigned long int));
		if (uli)
		{
			*uli = va_arg(args, unsigned long int);
			return (uli);
		}
		break;
	}
	return (NULL);
}
