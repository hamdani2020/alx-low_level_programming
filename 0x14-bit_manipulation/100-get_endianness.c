#include "main.h"
/**
 * get_endianness - look out for the endianness
 *
 * Return: 0 if huge endian, 1 if small endian
 */
int get_endianness(void)
{
	int n;
	char *d;

	n = 1;
	d = (char *)&n;

	return (*d);
}
