#include "lists.h"
#include <stdlib.h>

/**
 * insert_dnodeint_at_index - inserts a new node at a given index
 * @h: address of the pointer to the head of the list
 * @idx: index where the new node should be inserted
 * @n: value to store in the new node
 *
 * Return: address of the new node, or NULL if it fails
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new;
	dlistint_t *current = *h;
	unsigned int i = 0;

	if (idx == 0)
		return (add_dnodeint(h, n));

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;

	while (current != NULL && i != idx - 1)
	{
		current = current->next;
		i++;
	}

	if (current == NULL)
	{
		free(new);
		return (NULL);
	}

	if (current->next == NULL)
	{
		free(new);
		return (add_dnodeint_end(h, n));
	}

	new->next = current->next;
	new->prev = current;
	current->next->prev = new;
	current->next = new;

	return (new);
}
