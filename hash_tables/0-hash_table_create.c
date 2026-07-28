#include "hash_tables.h"
#include <stdlib.h>
/**
 * hash_table_create - Creates a hash table
 * @size: Size of the hash table array
 *
 * Return: Pointer to the new hash table, or NULL on failure
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *ht;
	unsigned long int i = 0;

	ht = malloc(sizeof(hash_table_t));

	if (ht == NULL)
	{
		return (NULL);
	}

	ht->size = size;

	ht->array = malloc(sizeof(hash_node_t *) * size);

	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}

	while (i < size)
	{
		ht->array[i] = NULL;
		i++;
	}

	return (ht);

}
