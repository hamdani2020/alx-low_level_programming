#include <stdio.h>

/**
 * premain - function that runs before main
 * Remain: 0
 */


void __attribute__((constructor)) premain()
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n);
}
