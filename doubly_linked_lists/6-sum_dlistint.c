#include "lists.h"
/**
 * sum_dlistint - returns the sum of all the data of a doubly linked list
 * @head: pointer to the head of the list
 *
 * Return: sum of all the node values
 */
int sum_dlistint(dlistint_t *head)
{
	dlistint_t *current = head;
	int sum = 0;

	while (current != NULL)
	{
		sum += current->n;
		current = current->next;
	}

	return (sum);

}
