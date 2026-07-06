#include "main.h"
#include <stdlib.h>
/**
 * _strdup - Duplicates a string in a newly allocated memory space
 * @str: String to duplicate
 *
 * Return: Pointer to the duplicated string, or NULL if it fails
 */

char *_strdup(char *str)
{
	int i;
	int len;
	char *cpy;

	i = 0;

	if (str == 0)
	{
		return (NULL);
	}

	for (len = 0; str[len] != '\0'; len++)
	{

	}

	cpy = malloc(sizeof(char) * (len + 1));

	if (cpy == NULL)
	{
		return (NULL);
	}

	while (i < len)
	{
		cpy[i] = str[i];
		i++;
		cpy[i] = '\0';
	}

return (cpy);
}
