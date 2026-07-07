#include "main.h"
#include <stdlib.h>
/**
 * array_range - creates an array of integers
 * @min: minimum value
 * @max: maximum value
 *
 * Return: pointer to the new array, or NULL on failure
 */
int *array_range(int min, int max)
{
	int *ptr;
	int i;
	int len;

	if (min > max)
	{
		return (NULL);
	}

	len = (max - min) + 1;

	ptr = malloc(sizeof(int) * len);

	if (ptr == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < len; i++)
	{
		ptr[i] = min + 1;
	}
	return (ptr);
}
