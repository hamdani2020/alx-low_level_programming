#include "main.h"

#define CHAR_BITS 8
#define INT_BITS (sizeof(unsigned long int) * CHAR_BITS)

/* 
 * Prints the binary representation of a decimal number
 */
void print_bin(unsigned long int number)
{
    if (number >> 1) {
        print_bin(number >> 1);
    }
    putc((number & 1) ? '1' : '0', stdout);
}

/* 
 * Sets the value of a bit to 0 at a given index 
 * Returns 1 if it worked, -1 if it failed
 */
int clear_bit(unsigned long int* n, unsigned int index)
{
    unsigned long int mask = 1;
    #ifdef DEBUG
    unsigned long int n_before = *n;
    #endif

    // check if index is greater than the size of n in binary
    if (index >= INT_BITS) {
        return -1;
    }

    mask = ~(mask << index); // create mask based on index position
    *n &= mask;

    #ifdef DEBUG
    printf("\n%ld in binary is ", n_before);
    print_bin(n_before);
    printf(" while NOT (~) of mask right shifted to index %d is ", index);
    print_bin(mask);
    printf(" our new value n in binary is ");
    print_bin(*n);
    printf("\n\n");
    #endif

    return 1;
}

