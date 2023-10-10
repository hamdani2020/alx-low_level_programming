#include "search_algos.h"

/**
 * linear_search - This searches the value in an array.
 * @array: array to search in.
 * @size: length of the array.
 * @value: value to look for.
 *
 * Return: The 1st index of the value in the array, else -1.
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
