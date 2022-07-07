#include "main.h"
#include <stdio.h>
#include <stdarg.h>

int (*print_format(const char *format))(va_list)
{
	int j = 0;

	print_t p[] = {
		{"c", print_c},
		{"s", print_s},
		{NULL, NULL}
	};

	for (; p[j].s != NULL; j++)
	{
		if (*(p[j].s) == *format)
			break;
	}
	return (p[j].i);
};

int _printf(const char *format, ...)
{
	va_list p;
	int (*f)(va_list);
	unsigned int i = 0, x = 0;

	if (format == NULL)
		return (-1);

	va_start(p, format);
	while (format && format[i])
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			x++;
			i++;
			continue;
		}
		else
		{
			if (format[i + 1] == '%')
			{
				_putchar('%');
				x++;
				i += 2;
				continue;
			}
			else
			{
				f = print_format(&format[i + 1]);
				if (f == NULL)
					return (-1);
				i += 2;
				x += f(p);
				continue;
			}
		}
		i++;
	}
	va_end(p);
	return (x);
}
