#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H
#include <stdio.h>

/**
 * struct skiplist_s - This is a singly linked list with an express lane.
 * @n: This is an integer stored at the node.
 * @index: This is an index of the node in the list.
 * @next: This pointer points to the next node.
 * @express: This is the pointer to the next node in the express lane.
 *
 */
typedef struct skiplist_s
{
	int n;
	size_t index;
	struct skiplist_s *next;
	struct skiplist_s *express;
} skiplist_t;

/**
 * struct listint_s - This is a singly linked list.
 * @n: This is integer stored at the node.
 * @index: This is the index of the node in the list.
 * @next: This pointer points to the next node.
 *
 * Description: This a singly linked list node structure.
 */

typedef struct listint_s
{
	int n;
	size_t index;
	struct listint_s *next;
} listint_t;


int binary_search(int *array, size_t size, int value);
int jump_search(int *array, size_t size, int value);
int linear_search(int *array, size_t size, int value);
int interpolation_search(int *array, size_t size, int value);
int exponential_search(int *array, size_t size, int value);
int advanced_binary(int *array, size_t size, int value);
listint_t *jump_list(listint_t *list, size_t size, int value);
skiplist_t *linear_skip(skiplist_t *list, int value);

#endif
