#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_all - Prints anything
 * @format: List of types of arguments passed to the function
 *
 * Return: Nothing
 */
void print_all(const char * const format, ...)
{
	va_list ap;
	char *separator = "";
	char *str;
	int i = 0;

	va_start(ap, format);

	while (format && format[i])
	{
		switch (format[i])
		{
		case 'c':
			printf("%s%c", separator, va_arg(ap, int));
			separator = ", ";
			break;
		case 'i':
			printf("%s%d", separator, va_arg(ap, int));
			separator = ", ";
			break;
		case 'f':
			printf("%s%f", separator, va_arg(ap, double));
			separator = ", ";
			break;
		case 's':
			str = va_arg(ap, char *);
			if (str == NULL)
				str = "(nil)";
			printf("%s%s", separator, str);
			separator = ", ";
			break;
		}
		i++;
	}

	va_end(ap);
	printf("\n");
}
