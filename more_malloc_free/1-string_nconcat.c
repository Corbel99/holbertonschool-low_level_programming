#include "main.h"
#include <stdlib.h>
/**
 * string_nconcat - concatenates two strings
 * @s1: first string
 * @s2: second string
 * @n: number of bytes from s2 to concatenate
 *
 * Return: pointer to the newly allocated string, or NULL on failure
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *ptr;
	int i;
	unsigned j;
	unsigned len_s1;
	unsigned len_s2;

	if (s1 == NULL)
		s1 = "";
	for (i = 0; s1[i] != '\0'; i++)
	;
	len_s1 = i;

	if (s2 == NULL)
		s2 = "";
	for (i = 0; s2[i] != '\0'; i++)
	;
	len_s2 = i;

	if (n >= len_s2)
		n = len_s2;

	ptr = malloc(len_s1 + n + 1);

	if (ptr == NULL)
		return (NULL);

	for (i = 0; s1[i] != '\0'; i++)
		ptr[i] = s1[i];

	for  (j = 0; j < n; j++)
		ptr[i + j] = s2[j];

	ptr[i + j] = '\0';

	return (ptr);
}
