#include "hash_tables.h"
#include <stdio.h>
/**
 * hash_table_print - Prints a hash table
 * @ht: Pointer to the hash table
 *
 * Return: Nothing
 */

void hash_table_print(const hash_table_t *ht)
{
	int first = 1;
	unsigned long int index;
	hash_node_t *current;

	if (ht == NULL)
		return;

	printf("{");

	for (index = 0; index < ht->size; index++)
	{
		current = ht->array[index];

		while (current != NULL)
		{
			if (first == 0)
			{
				printf(", ");
			}
			printf("'%s': '%s'", current->key, current->value);
			first = 0;
			current = current->next;
		}
	}
	printf("}\n");
}
