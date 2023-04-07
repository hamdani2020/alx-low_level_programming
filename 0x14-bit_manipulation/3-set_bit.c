#include "main.h"

/* Size of char */
#define CHAR_BITS 8 

/* Size of unsigned long int in binary coded decimal */
#define INT_BITS (sizeof(unsigned long int) * CHAR_BITS)

/**
 * print_bin - prints binary representation of @n
 *
 * @number: decimal value
 *
 * Return: void
 */
void print_bin(unsigned long int number)
{
	/* Recursive function to print binary representation of number */
	if (number >> 1)
		print_bin(number >> 1);

	/* Prints binary digit of number */
	putc((number & 1) ? '1' : '0', stdout);
}

/**
 * set_bit - sets the value of a bit to 1 at a given index.
 *
 * @n: number
 * @index: index to set the value of bit to 1
 *
 * Return: 1 if successful or -1 if failed
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	/* Create mask to set bit to 1 */
	unsigned long int mask = 1;

	#ifdef DEBUG
	/* Debugging purpose */
	unsigned long int n_before = *n;
	#endif

	/* Return -1 if index is greater than the size of n in binary coded decimal */
	if (index > INT_BITS)
		return (-1);

	/* Shift the mask to the index position */
	mask <<= index;

	/* Set the value of bit to 1 at index position */
	*n = (*n | mask);

	#ifdef DEBUG
	/* Debugging purpose */
	printf("\n%ld in binary is ", n_before);
	print_bin(n_before);
	printf(" while mask right shifted to index %d is ", index);
	print_bin(mask);
	printf(" our new value n in binary is ");
	print_bin(*n);
	printf("\n\n");
	#endif

	return (1);
}

