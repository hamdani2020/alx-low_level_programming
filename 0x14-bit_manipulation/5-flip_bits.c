#include "main.h"
/**
 * flip_bits - flip to get starting with one number then onto the next
 * @x: the initial number
 * @y: the subsequent number
 * Return: the number of bits you would have to flip
 */
unsigned int flip_bits(unsigned long int x, unsigned long int y)
{
	unsigned long int differnce, result;
	unsigned int k, i;

	k = 0;
	result = 1;
	differnce = x ^ y;
	for (i = 0; i < (sizeof(unsigned long int) * 8); i++)
	{
		if (result == (differnce & result))
			k++;
		result <<= 1;
	}

	return (k);
}
