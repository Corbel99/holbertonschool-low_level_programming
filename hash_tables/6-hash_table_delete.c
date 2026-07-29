#include "hash_tables.h"
#include <stdlib.h>
/**
 * hash_table_delete - Deletes a hash table
 * @ht: Pointer to the hash table
 *
 * Return: Nothing
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *current, *next;
	unsigned long int index;

	if (ht == NULL)
		return;

	for (index = 0; index < ht->size; index++)
	{
		current = ht->array[index];

		while (current != NULL)
		{
			next = current->next;
			free(current->value);
			free(current->key);
			free(current);

			current = next;
		}
	}
	free(ht->array);
	free(ht);
}
