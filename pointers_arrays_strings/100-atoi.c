#include "main.h"

/**
 * _atoi - Converts a string to an integer
 * @s: Pointer to the string to convert
 *
 * Return: The converted integer
 */
int _atoi(char *s)
{
	int i;
	int result;
	int sign;

	i = 0;
	result = 0;
	sign = 1;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
			sign = -sign;

		if (s[i] >= '0' && s[i] <= '9')
		{
			while (s[i] >= '0' && s[i] <= '9')
			{
				result = result * 10 + (s[i] - '0');
				i++;
			}
			return (result);		}
		i++;
	}

	return (0);
}
