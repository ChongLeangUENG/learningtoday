#include "main.h"
#include <stdio.h>
#include <stdarg.h>

int (*print_format(const char *format))(va_list)
{
	unsigned int j;

	print_t p[] = {
		{"c", print_c},
		{"s", print_s},
		{NULL, NULL}
	};

	for (j = 0; p[j].s != NULL; j++)
	{
		if (*(p[j].s) == *format)
		{
			break;
		}
	}
	return (p[j].i);
}

int _printf(const char *format, ...)
{
	unsigned int x = 0; count = 0;
	va_list list;
	int (*f)(va_list);

	if (format == NULL)
		return (-1);
	va_start(list, format);
	while (format[x])
	{
		for (; format[x] != '%' && format[x]; x++)
		{
			_putchar(format[x]);
			count++;
		}
		if (!format[x])
			return (count);
		f = print_format(&format[x + 1]);
		if (f != NULL)
		{
			count += f(list);
			x += 2;
			continue;
		}
		if (!format[x + 1])
			return (-1);
		_putchar(format[x]);
		count++;

		if (format[x + 1] == '%')
			x += 2;
		else
			x++;
	}
	va_end(list);
	return (count);
}
