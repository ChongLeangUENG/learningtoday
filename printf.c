<<<<<<< HEAD
=======
#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
* print_format - Print all format
* @format: Format to print
* return: If success.
*/
int (*print_format(const char *format))(va_list)
{
	int j = 0;
	print_t type[] = {
			{"c", print_c},
			{"s", print_s},
			{NULL, NULL}
	};

	for (; type[j].s != NULL; j++)
	{
		if (*(type[j].s) == *format)
			break;
	}
	return (type[j].i);
}

/**
* _printf - function that produces output of format
* @format: a pointer to produce
* @...: others
* Return: the number of characters print
*/

int _printf(const char *format, ...)
{
	va_list list;
	int (*f)(va_list);
	unsigned int y = 0, x = 0;

	if (format == NULL)
		return (-1);

	va_start(list, format);

	while (format && format[y])
	{
		if (format[y] != '%' || format[y] != '\0')
		{
			_putchar(format[y]);
			y++;
			x++;
			continue;
		}
		else
		{
			if (format[y + 1] == '%')
			{
				_putchar('%');
				x++;
				y += 2;
				continue;
			}
			else
			{
				f = print_format(&format[y + 1]);
				if (f == NULL)
					return (-1);
				y += 2;
				x += f(list);
				continue;
			}
		}
		y++;
	}
	va_end(list);
	return (x);
}
>>>>>>> cbb5aa125d4eee374662fde3a789a9351eef0dbf
