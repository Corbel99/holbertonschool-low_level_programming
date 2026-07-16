#include <stdio.h>
#include "variadic_functions.h"
/**
 * print_numbers - prints numbers followed by a new line
 * @separator: string to be printed between numbers
 * @n: number of integers passed to the function
 *
 * Return: nothing
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	unsigned int i = 0;
	va_list ap;

	va_start(ap, n);

	while (i < n)
	{
		if (i != 0 && separator != NULL)
		{
			printf("%s", separator);
		}
		printf("%d", va_arg(ap, int));
		i++;
	}
	va_end(ap);
	printf("\n");
}
