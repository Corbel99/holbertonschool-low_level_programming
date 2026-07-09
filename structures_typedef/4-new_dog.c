#include "dog.h"
#include <stdlib.h>

/**
 * new_dog - creates a new dog
 * @name: dog's name
 * @age: dog's age
 * @owner: dog's owner
 *
 * Return: pointer to the new dog, or NULL if it fails
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *newdog;
	int i, len_name = 0, len_owner = 0;

	while (name[len_name] != '\0')
		len_name++;

	while (owner[len_owner] != '\0')
		len_owner++;

	newdog = malloc(sizeof(dog_t));
	if (newdog == NULL)
		return (NULL);

	newdog->name = malloc(sizeof(char) * (len_name + 1));
	if (newdog->name == NULL)
	{
		free(newdog);
		return (NULL);
	}

	newdog->owner = malloc(sizeof(char) * (len_owner + 1));
	if (newdog->owner == NULL)
	{
		free(newdog->name);
		free(newdog);
		return (NULL);
	}

	for (i = 0; i <= len_name; i++)
		newdog->name[i] = name[i];

	for (i = 0; i <= len_owner; i++)
		newdog->owner[i] = owner[i];

	newdog->age = age;

	return (newdog);
}
