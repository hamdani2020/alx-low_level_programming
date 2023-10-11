#include "search_algos.h"
#include <stdio.h>
#include <stddef.h>
/**
 * linear_search - This searches for a value in an array of
 * @array: This is the array to search the value in
 * @size: This is the size of the array
 * @value: This is the value to look for
 *
 * Return: the index of the found value
 */

int linear_search(int *array, size_t size, int value)
{
	size_t i = 0;

	if (array == NULL)
		return (-1);

	for (i = 0; i < size; i++)
	{
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
	}
	return (-1);
}
