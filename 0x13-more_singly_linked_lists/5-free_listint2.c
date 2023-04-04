#include "lists.h"
#include <stdlib.h>

/**
 * free_listint2 - function that frees a listint_t list
 * @head: a double pointer of lists
 *
 * Return: void
 */

void free_listint2(listint_t **head)
{
	if (head == NULL || *head == NULL) {
		return;
	}

	listint_t *current = *head;
	while (current != NULL) {
		listint_t *next = current->next;
		free(current);
		current = next;
	}

	*head = NULL;
}

