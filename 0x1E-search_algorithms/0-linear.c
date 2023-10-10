#include "search_algos.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

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
	size_t j = 0;

	if (!array || size == 0)
		return (-1);

	while (j < size)
	{
		printf("Value checked array[%lu] = [%d]\n", j, array[j]);
		if (array[j] == value)
			return (j);
		j++;
	}

	return (-1);
}

