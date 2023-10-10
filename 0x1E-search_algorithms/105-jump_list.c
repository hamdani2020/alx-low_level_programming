#include <math.h>
#include "search_algos.h"

/**
 * move_forward - moves a list forward until the index matches a desired
 * index, or the last node in the list
 * @list: This is the list to move forward
 * @index: index
 *
 * Return: node with desired index
 */
listint_t *move_forward(listint_t *list, size_t index)
{
	while (list->next != NULL && list->index < index)
		list = list->next;
	return (list);
}

/**
 * jump_list - searches for a value in a sorted list of integers using
 * @list: The pointer to the head of the list to search in
 * @size: The number of nodes in list
 * @value: The value to search for
 *
 * Return: The pointer to the first node where value is located
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t j;
	listint_t *left, *right;

	if (list != NULL && size > 0)
	{
		j = sqrt(size);
		left = list;
		right = move_forward(left, j);
		printf("Value checked at index [%lu] = [%d]\n", right->index, right->n);
		while (right->index < (size - 1) && right->n < value)
		{
			left = right;
			right = move_forward(left, right->index + j);
			printf("Value checked at index [%lu] = [%d]\n", right->index, right->n);
		}
		printf("Value found between indexes [%lu] and [%lu]\n",
				left->index, right->index);
		printf("Value checked at index [%lu] = [%d]\n", left->index, left->n);
		while (left->index < size - 1 && left->n < value)
		{
			left = left->next;
			if (left == NULL)
				return (NULL);
			printf("Value checked at index [%lu] = [%d]\n", left->index, left->n);
		}
		if (left->n == value)
			return (left);
	}
	return (NULL);
}

