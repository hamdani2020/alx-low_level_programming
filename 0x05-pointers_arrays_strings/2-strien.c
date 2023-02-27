#include "main.h"

/**
 * _strien - returns the length of a string
 * @s: input sting
 *
 * Return: length of a string.
 */

int _strien(char *s)
{
	int count = 0;

	while (*(s + count) != '\0')
		count++;

	return (count);
}
