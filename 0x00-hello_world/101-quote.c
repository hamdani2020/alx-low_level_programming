#include <stdio.h>
/**
 * main - print the size of various types
 *
 * Description: prints the size of various types on the computer it is compiled
 * and run on
 *
 * Return: Always 0 (Success)
 */


int main() {
    char *msg = "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";
    write(STDERR_FILENO, msg, 42);
    return 1;
}
