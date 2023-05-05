#include "main.h"

/**
 * set_bit - the worth of a bit to one 1 at a given index.
 * @record: beginning from zero 0 of the bit you want to set
 * @b: pointer number of i
 * Return: one 1 if it succeed, or -1 if an error occurred
 */
int set_bit(unsigned long int *b, unsigned int record)
{
	unsigned long int i;

	if (record > (sizeof(unsigned long int) * 8 - 1))
		return (-1);
	i = 1 << record;
	*b = *b | i;

	return (1);
}

