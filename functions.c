#include <unistd.h>
int _putchar(char c)
{
	return (write(1, &c, 1));
}
int print_int(void *p)
{
	int num = *p;
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
			out = (print_int(num / 10) + 1);
			_putchar((num % 10) + '0');
			return (out);
		}
	}
	else
	{
		_putchar('-');
		return (print_int(num * -1) + 1);
	}
}
int print_str(void *p)
{
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
}
int print_char(void *p)
{
	return (_putchar(*p));
}
