#include "search_algos.h"

int recurse_helper(int *arr, size_t size, int val, size_t ix);

/**
 * linear_search -This searches for value in an integer array
 * @array: The pointer to array of ints
 * @size: The size of array
 * @value: The value to locate
 */
int linear_search(int *array, size_t size, int value)
{

	if (array == NULL)
		return (-1);

	return (recurse_helper(array, size, value, 0));
}
/**
 * recurse_helper - recursive implement of linear search
 * @arr: The pointer to array of ints
 * @size: The size of array
 * @val: The value to locate
 * @ix: The current index
 *
 * Return: index of value; -1 if value not found
 */
int recurse_helper(int *arr, size_t size, int val, size_t ix)
{
	if (ix == size)
		return (-1);

	printf("Value checked array[%lu] = [%d]\n", ix, arr[ix]);

	if (arr[ix] == val)
		return (ix);

	return (recurse_helper(arr, size, val, ix + 1));
}
