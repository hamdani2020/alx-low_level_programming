#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index.
 * @b: actually looking at bits
 * @record: which to actually looking at bit
 *
 * Return: the worth of the bit at index
 */
int get_bit(unsigned long int b, unsigned int record)
{
	unsigned long int div, rest;

	if (record > (sizeof(unsigned long int) * 8 - 1))
		return (-1);
	div = 1 << record;
	rest = b & div;
	if (rest == div)
		return (1);

	return (0);
}
