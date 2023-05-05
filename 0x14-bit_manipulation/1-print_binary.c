#include "main.h"
/**
 * _power - compute (base and power)
 * @b: base of the exponet
 * @p: power of the exponet
 * Return: value of base and power
 */
unsigned long int _power(unsigned int b, unsigned int p)
{
	unsigned long int n;
	unsigned int i;

	n = 1;
	for (i = 1; i <= p; i++)
		n *= b;
	return (n);
}
/**
 * print_binary - prints the binary representation of a number
 * @m: number of printed
 * Return: void
 */
void print_binary(unsigned long int m)
{
	unsigned long int dev, result;
	char flag;

	flag = 0;
	dev = _power(2, sizeof(unsigned long int) * 8 - 1);

	while (dev != 0)
	{
		result = m & dev;
		if (result == dev)
		{
			flag = 1;
			_putchar('1');

		}
		else if (flag == 1 || dev == 1)
		{
			_putchar('0');
		}
		dev >>= 1;
	}
}
