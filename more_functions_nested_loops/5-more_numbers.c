#include "main.h"

/**
 * more_numbers - prints the numbers from 0 to 14 ten times
 */
void more_numbers(void)
{
	int n;
	int i;

	for (n = 0; n < 10; n++)
	{
		for (i = 0; i <= 14; i++)
		{
			if (i > 9)
			{
				_putchar(i / 10 + '0');
				_putchar(i % 10 + '0');
			}
			else
			{
				_putchar(i + '0');
			}
		}
		_putchar('\n');
	}
}
