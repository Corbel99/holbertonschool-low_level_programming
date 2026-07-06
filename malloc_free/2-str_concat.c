#include "main.h"
#include <stdlib.h>

/**
 * str_concat - Concatenates two strings into a new allocated memory
 * @s1: First string
 * @s2: Second string
 *
 * Return: Pointer to the concatenated string, or NULL if it fails
 */
char *str_concat(char *s1, char *s2)
{
	int i, j, lena, lenb;
	char *concat;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	for (lena = 0; s1[lena] != '\0'; lena++)
		;

	for (lenb = 0; s2[lenb] != '\0'; lenb++)
		;

	concat = malloc(sizeof(char) * (lena + lenb + 1));
	if (concat == NULL)
		return (NULL);

	for (i = 0; i < lena; i++)
		concat[i] = s1[i];

	for (j = 0; j < lenb; j++)
		concat[i + j] = s2[j];

	concat[i + j] = '\0';

	return (concat);
}
