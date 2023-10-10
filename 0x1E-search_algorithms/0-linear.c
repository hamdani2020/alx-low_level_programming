#include "search_algos.h"

/**
 * linear_search - This searches a value in an array.
 * @array: Array to search in.
 * @size: Length of the array.
 * @value: Value to look for.
 *
 * Return: The first index of the value in the
 */

int linear_search(int *array, size_t size, int value)
{
	size_t j;

	for (j = 0; (j < size) && (array); j++)
	{
		if (*(array + j) == value)
		{
			printf("Value checked array[%d] = [%d]\n", (int)j, *(array + j));
			return (j);
		}
		else
		{
			printf("Value checked array[%d] = [%d]\n", (int)j, *(array + j));
		}
	}
	return (-1);
}

