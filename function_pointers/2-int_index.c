#include "function_pointers.h"
/**
 * int_index - searches for an integer
 * @array: pointer to the array
 * @size: number of elements in the array
 * @cmp: function used to compare each element
 *
 * Return: index of the first matching element, or -1 if no match
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i = 0;

	if (size <= 0 || array == NULL || cmp == NULL)
	{
		return (-1);
	}

	while (i < size)
	{
		if (cmp(array[i]) != 0)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}
