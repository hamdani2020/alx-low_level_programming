#include "search_algos.h"

/**
 * interpolation_search - This searches for a value in the sorted array using
 * @array: Array to search in.
 * @size: Length of the array.
 * @value: Value to look for.
 *
 * Return: The iniatial value index of the value in the array,else -1.
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t low = 0, high = size - 1, position = 0;
	double tmpe;

	if (!array)
		return (-1);
	while (array[high] != array[low])
	{
		tmpe = (double)(high - low) / (array[high] - array[low]);
		position = low + (tmpe * (value - array[low]));
		if (position >= size)
		{
			printf("Value checked array[%d] is out of range\n", (int)position);
			break;
		}
		printf("Value checked array[%d] = [%d]\n", (int)position, array[position]);
		if (array[position] == value)
			return (position);
		else if (array[position] < value)
			low = position + 1;
		else
			high = position - 1;
	}
	return (value == array[low] ? (int)low : -1);
}
