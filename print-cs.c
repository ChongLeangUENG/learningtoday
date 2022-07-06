#include "main.h"

int print_c(va_list c)
{
	char charact = (char)va_arg(c, int);
	
	_putchar(charact);
	return (1);
}


int print_s(va_list s)
{
	char *string = va_arg(s, char*);
	int i = 0;

	 if (string == NULL)
		 string = "";
	 while (string[i])
		 _putchar(string[i++]);
	 return (i);
}


