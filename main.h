#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include <stdarg.h>
typedef struct print
{
	char *s;
	int (*i)(va_list);

} print_f;

int _putchar(char c);
int _printf(const char *format, ...);
int print_c(va_list c);
int print_s(va_list s);
int print_percent(va_list %);
#endif

