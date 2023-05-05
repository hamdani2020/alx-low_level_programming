#include "main.h"

/**
 * binary_to_uint -changes binary number to an unsigned int.
 * @x: pointing to a string of 0 and 1 chars
 *
 * Return:changed number, or 0
 */
unsigned int binary_to_uint(const char *x)
{
	int iterate;
	unsigned int p;

	p = 0;
	if (!x)
		return (0);
	for (iterate = 0; x[iterate] != '\0'; iterate++)
	{
		if (x[iterate] != '0' && x[iterate] != '1')
			return (0);
	}
	for (iterate = 0; x[iterate] != '\0'; iterate++)
	{
		p <<= 1;
		if (x[iterate] == '1')
			p += 1;
	}
	return (p);
}
