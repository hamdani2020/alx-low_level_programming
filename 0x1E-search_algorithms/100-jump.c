#include <math.h>
#include "search_algos.h"

/**
 * minimum_value - This finds the minimum of two values
 * @x: this is the first value to compare
 * @y: this is the second value to compare
 *
 * Return: Smaller of the two values, or a if is equavalent
 */
size_t minimum_value(size_t x, size_t y)
{
	if (y < x)
		return (y);
	return (x);
}


/**
 * jump_search - it searches for a value in a sorted array of integers using the
 * Jump search algorithm
 * @array: This pointer points to the first element of the array to search in
 * @size: number of elements in array or the length of the array
 * @value: value for the search
 *
 * Return: first index where value is located, or -1 on failure
 */
int jump_search(int *array, size_t size, int value)
{
	size_t m, n, jump;
	int val;

	if (array != NULL && size > 0)
	{
		jump = sqrt(size);
		m = 0;
		n = jump;
		val = array[m];
		printf("Value checked array[%lu] = [%d]\n", m, val);
		while (n < size && val < value)
		{
			if (array[n] >= value)
				break;
			m += jump;
			n += jump;
			val = array[m];
			printf("Value checked array[%lu] = [%d]\n", m, val);
		}
		if (m >= size || val > value)
			return (-1);
		printf("Value found between indexes [%lu] and [%lu]\n", m, n);
		while (m <= minimum_value(size - 1, n) && val <= value)
		{
			val = array[m];
			printf("Value checked array[%lu] = [%d]\n", m, val);
			if (val == value)
				return (m);
			m++;
		}
	}
	return (-1);
}
