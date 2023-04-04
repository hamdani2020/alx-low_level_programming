#include "lists.h"
#include <stdio.h>

/**
 * print_listint - Prints all the elements of a singly linked list of integers.
 * @h: Pointer to the head of the linked list.
 * Return: The number of nodes in the linked list.
 */
size_t print_listint(const listint_t *h)
{
	size_t count = 0;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		count++;
	}

	return (count);
}

