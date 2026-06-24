#include "main.h"
/**
 * _islower - checks for lowercase character
 * @c: character to check
 *
 * Return: 1 if lowercase, 0 otherwise
 */
void print_alphabet_x10(void)
{
	int i;
	char c;

	for (i = 0; i < 10; i++)
	{
		c = 'a';

		while (c <= 'z')
		{
			_putchar(c);
			c++;
		}
		_putchar('\n');
	}
}
