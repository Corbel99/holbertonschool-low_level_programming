#include "main.h"
/**
 * puts_half - Prints the second half of a string
 * @str: Pointer to the string
 */
void puts_half(char *str)
{
	int len;
	int debut;

	for (len = 0; str[len] != '\0'; len++)
	{

	}
	if (len % 2 == 0)
	{
		debut = len / 2;
	}
	else
	{
		debut = (len - 1) / 2;
	}
	while (str[debut] != '\0')
	{
		_putchar(str[debut]);
		debut++;
	}
	_putchar('\n');
}
