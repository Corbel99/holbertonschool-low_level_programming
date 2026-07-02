#include "main.h"

/**
 * _strchr - Locates a character in a string
 * @s: String to search in
 * @c: Character to locate
 *
 * Return: Pointer to the first occurrence of c, or NULL if not found
 */
char *_strchr(char *s, char c)
{
int i;

for (i = 0; s[i] != '\0'; i++)
{
	if (s[i] == c)
	{
		return (s + i);
	}
}
return ("NULL");
}
