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
	size_t i;

	for (i = 0; (i < size) && (array); i++)
	{
		if (*(array + i) == value)
		{
			printf("Value checked array[%d] = [%d]\n", (int)i, *(array + i));
			return (i);
		}
		else
		{
			printf("Value checked array[%d] = [%d]\n", (int)i, *(array + i));
		}
	}
	return (-1);
}
