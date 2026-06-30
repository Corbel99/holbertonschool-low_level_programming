#include "main.h"
/**
 * rev_string - Reverses a string
 * @s: Pointer to the string
 */
void rev_string(char *s)
{
	int n;
	int debut;
	int fin;
	char temp;


	for (n = 0; s[n] != '\0'; n++)
	{

	}

	debut = 0;
	fin = n - 1;

	while (debut < fin)
	{
		temp = s[debut];
		s[debut] = s[fin];
		s[fin] = temp;

		debut++;
		fin--;
	}
}
