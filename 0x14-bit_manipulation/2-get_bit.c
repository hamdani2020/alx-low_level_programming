#include "main.h"

#define BITS_PER_CHAR 8 // Number of bits in a char
#define BITS_PER_INT (sizeof(unsigned long int) * BITS_PER_CHAR) // Number of bits in an unsigned long int

/**
 * print_binary - Prints the binary representation of a given decimal number.
 *
 * @number: The decimal number to print.
 *
 * Returns: 0
 */
void print_binary(unsigned long int number)
{
    if (number >> 1)
    {
        print_binary(number >> 1);
    }

    putc((number & 1) ? '1' : '0', stdout);
}

/**
 * get_bit - Gets the value of the bit at the specified index in a given decimal number.
 *
 * @number: The decimal number to get the bit from.
 * @index: The index of the bit to get.
 *
 * Returns: The value of the bit at the specified index, or -1 if an error occurred.
 */
int get_bit(unsigned long int number, unsigned int index)
{
    // Check if the index is greater than the number of bits in an unsigned long int
    if (index > BITS_PER_INT)
    {
        return -1;
    }

    #ifdef DEBUG
    printf("\n[%lu >> %d] is %lu.\n", number, index, (number >> index));
    printf("%lu in binary: ", number);
    print_binary(number);
    printf("\n[%lu >> %d] in binary: ", number, index);
    print_binary(number >> index);
    printf(" <- last bit is the bit at index %d\n\n", index);
    #endif

    int bit = ((number >> index) & 1); // Shift the number right by the index and use bitwise AND to get the value of the bit

    return bit;
}

