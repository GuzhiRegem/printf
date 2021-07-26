#include <unistd.h>
#include <stdio.h>
int _putchar(char c)
{
	return (write(1, &c, 1));
}
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
int print_str(char *p)
{
	char *str;
	str = p;
	if (str)
	{
		if (!str[0])
			return (0);
		else
		{
			_putchar(str[0]);
			return(print_str(str + 1) + 1);
		}
	}
	else
		print_str("(nil)");
	return(0);
}
int print_char(int *p)
{
	return (_putchar((int)*p));
}
int print_int(int *p)
{
	return (_print_int((int)*p));
}
