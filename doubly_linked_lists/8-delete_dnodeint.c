#include "lists.h"
#include <stdlib.h>
/**
 * delete_dnodeint_at_index - deletes the node at a given index
 * @head: address of the pointer to the head of the list
 * @index: index of the node to delete
 *
 * Return: 1 if successful, -1 if it fails
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current = *head;
	unsigned int i = 0;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		current = *head;
		*head = (*head)->next;

	if (*head != NULL)
	(*head)->prev = NULL;

	free(current);

	return (1);
	}
	while (current != NULL && i < index)
	{
		current = current->next;
		i++;
	}

	if (current == NULL)
	return (-1);

	if (current->next == NULL)
	{
		current->prev->next = NULL;
		free(current);
		return (1);
	}

	current->prev->next = current->next;
	current->next->prev = current->prev;
	free(current);
	return (1);
}
