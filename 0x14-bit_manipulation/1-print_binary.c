#include "main.h"

/**
 * debug_1 - print debug statements
 *
 * @n: value of n
 * @length: length of n
 * @mask: mask of n
 *
 * Return: 0
*/
void debug_1(unsigned long int n, int length, unsigned long int mask)
{
	printf("Length of %lu (n) is %i ", n, (length + 1));
	printf("and mask (original value 1) ");
	printf("is %lu based ", mask);
	printf("on [length of n - 1] == %i.\n\n", length);
}


/**
 * debug_2 - print debug statements
 *
 * @n: value of n
 * @mask: mask of n
 *
 * Return: 0
*/
void debug_2(unsigned long int n, unsigned long int mask)
{
	printf("Value of n is %lu, ", n);
	printf("value of mask is %lu and ", mask);
	printf("value of [n & mask] is %lu.\n\n", (n & mask));
}

/**
 * debug_3 - print debug statements
 *
 * @mask: mask of value n
 *
 * Return: nothing
*/
void debug_3(unsigned long int mask)
{
	printf("\nValue of mask is %lu after right shifting by one.\n\n", mask);
}

/**
 * _length - find the length of @n
 *
 * @n: value to find its length
 *
 * Return: length
*/
int _length(unsigned long int n)
{
	int length = 0;

	while (n > 0)
	{
		#ifdef DEBUG
		printf("Value of n is %lu before right shifting by one.\n\n", n);
		#endif

		length++;
		n >>= 1;

		#ifdef DEBUG
		printf("Value of n is %lu after right shifting by one.\n\n", n);
		#endif
	}

	length--;

	return (length);
}

/**
 * print_binary - a function that converts a decimal to binary
 *
 * @n: decimal number to convert
 *
 * Return: 0
*/
void print_binary(unsigned long int n)
{
	int length;
	unsigned long int mask = 1;

	length = _length(n);

	if (length > 0)
		mask <<= length;
	#ifdef DEBUG
	debug_1(n, length, mask);
	#endif

	while (mask > 0)
	{
		#ifdef DEBUG
		debug_2(n, mask);
		#endif

		if (n & mask)
			_putchar('1');
		else
			_putchar('0');

		mask >>= 1;

		#ifdef DEBUG
		debug_3(mask);
		#endif
	}
}
