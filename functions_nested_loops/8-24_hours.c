#include "main.h"
/**
 * jack_bauer - prints every minute of the day
 */
void jack_bauer(void)
{
	int n;
	int i;

	for (n = 0; n <= 23; n++)
	{
		for (i = 0; i <= 59; i++)
		{
		_putchar (n / 10 + '0');
		_putchar(n % 10 + '0');
		_putchar(':');
		_putchar (i / 10 + '0');
		_putchar(i % 10 + '0');
		_putchar('\n');
	}

}
}
