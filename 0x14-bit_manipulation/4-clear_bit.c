#include "main.h"

/**
 * clear_bit - sets the worth of  bit to zero 0 at a given index.
 * @num: number  of i
 * @record: beginning from zero 0 of the bit you want to set
 * Return: 1 if it succeeded, or -1 if a mistake occurred
 */

int clear_bit(unsigned long int *num, unsigned int record)
{
	unsigned long int i;

	if (record > (sizeof(unsigned long int) * 8 - 1))
		return (-1);
	i = ~(1 << record);
	*num = *num & i;

	return (1);
}
