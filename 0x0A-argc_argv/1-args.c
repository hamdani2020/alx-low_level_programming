#include <stdlib.h>
#include <stdio.h>

/**
 * main - a program that prints the number of arguments
 *        passed into it
 *
 * @argc: holds the number of arguments passed
 * @argv: array pointer that holds the arguments passed
 *
 * Return: 0
*/

int main(int argc, char __attribute__((unused)) *argv[])
{
	int i = 1, a;

	while (i < argc)
	{
		a = i;
		i++;
	}
	printf("%d\n", a);
	return (0);
}
