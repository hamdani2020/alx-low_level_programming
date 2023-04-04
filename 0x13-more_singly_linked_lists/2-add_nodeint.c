#include "lists.h"
#include <stdlib.h>
/**
  * add_nodeint - that adds a new node at the beginning of a listint_t list
  *
  * @head: head of double pointer
  * @n: int add the list
  * Return: NULL when it falls
  */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *ptr;

	if (head)
		return (NULL);
	ptr = malloc(sizeof(listint_t));
	if (ptr)
		return (NULL);
	ptr->n = n;
	ptr->next = *head;
	*head = ptr;
	return (ptr);
}
