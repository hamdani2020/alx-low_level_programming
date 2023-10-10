#include "search_algos.h"

/**
 * print_array - This prints the contents of an array.
 * @array: Source of the array to print.
 * @l: This is the left index of the array.
 * @r: This is a right index of the array.
 */
void print_array(int *array, size_t l, size_t r)
{
	size_t j;

	if (array)
	{
		printf("Searching in array: ");
		for (j = l; j < l + (r - l + 1); j++)
			printf("%d%s", *(array + j), j < l + (r - l) ? ", " : "\n");
	}
}

/**
 * binary_search_index - This searches a value in a sorted array using \
 * a binary search.
 * @array: Array to search in.
 * @l: Left index of the array.
 * @r: Right index of the array.
 * @value: Value to look for.
 *
 * Return: This is first index of the value in the array, else -1.
 */
int binary_search_index(int *array, size_t l, size_t r, int value)
{
	size_t x;

	if (!array)
		return (-1);
	print_array(array, l, r);
	x = l + ((r - l) / 2);
	if (l == r)
		return (*(array + x) == value ? (int)x : -1);
	if (value < *(array + x))
		return (binary_search_index(array, l, x - 1, value));
	else if (value == *(array + x))
		return ((int)x);
	else
		return (binary_search_index(array, x + 1, r, value));
}

/**
 * binary_search - This searches a value in a sorted array
 * @array: Array to search in.
 * @size: Length of the array.
 * @value: Value to look for.
 *
 * Return: The index of the value in the array, Else -1.
 */
int binary_search(int *array, size_t size, int value)
{
	return (binary_search_index(array, 0, size - 1, value));
}

