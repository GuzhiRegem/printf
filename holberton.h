#ifndef HOLBERTON_H
#define HOLBERTON_H

int _printf(const char *format, ...);
int _putchar(char c);
int print_char(char *p);
int print_int(int *p);
int print_str(char *p);

int print_binary(int *p);
int print_uint(unsigned int *p);
int print_octa(int *p);
int print_lowhex(int *p);
int print_uphex(int *p);
int print_unf_str(char *p);
int print_pointer(void *p);
int print_rev(char *p);
int print_ROT(char *p);
int print_long_int(long int *p);
int print_long_uint(unsigned long int *p);
int print_long_octa(long int *p);
int print_long_lowhex(long int *p);
int print_long_uphex(long int *p);
#endif
