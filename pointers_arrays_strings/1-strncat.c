#include "main.h"
/**
 * _strncat - Concatenates two strings using at most n bytes from src
 * @dest: Destination string
 * @src: Source string
 * @n: Maximum number of bytes to copy from src
 *
 * Return: Pointer to dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int i;
	int j;

	j = 0;

	for (i = 0; dest[i] != '\0'; i++)
	{

	}

	while (src[j] != '\0' && j != n)
	{
		dest[i] = src[j];

		i++;
		j++;
	}
	dest[i] = '\0';

	return (dest);
}
