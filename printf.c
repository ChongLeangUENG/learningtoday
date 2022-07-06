#include "main.h"
#include <stdio.h>
#include <stdarg.h>

int (*print_format(const char *format))(va_list)
{
	print_f type[] = {
		{"c", print_c},
		{"s", print_s},
		{NULL, NULL}
	};

	int i = 0;

	for (; type[i].t != NULL; i++)
	{
		if (*(type[i].t) == *format)
			break;
	}
	return (type[i].f);
}

int _printf(const char *format, ...)
{
	va_list p;
	int (*F)(va_list);
	unsigned int i = 0; x = 0;

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
				z += f(p);
				continue;
			}
		}
		i++;
	}
	va_end(p);
	return (x);
}
