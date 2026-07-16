#include <stdio.h>
#include "variadic_functions.h"
/**
 * print_strings - prints strings followed by a new line
 * @separator: string to be printed between strings
 * @n: number of strings passed to the function
 *
 * Return: nothing
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	char *str;
	unsigned int i = 0;

	va_list ap;

	va_start(ap, n);

	while (i < n)
	{
		if (i != 0 && separator != NULL)
		{
			printf("%s", separator);
		}

		str = va_arg(ap, char *);

		if (str != NULL)
		{
			printf("%s", str);
		}
		else
		{
			printf("(nil)");
		}

		i++;
	}

	va_end(ap);

	printf("\n");
}
