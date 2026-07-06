#include "main.h"
#include <stdlib.h>
/**
 * create_array - Creates an array of chars and initializes it
 * @size: Size of the array
 * @c: Character used to initialize the array
 *
 * Return: Pointer to the allocated array, or NULL if it fails
 */

char *create_array(unsigned int size, char c)
{
	unsigned int i;
	char *array;

	i = 0;

	if (size == 0)
	{
		return (NULL);
	}

	array = malloc(sizeof(char) * size);

	if (array == NULL)
	{
		return (NULL);
	}

	while (i < size)
	{
		array[i] = c;
		i++;
	}
	return (array);
}
