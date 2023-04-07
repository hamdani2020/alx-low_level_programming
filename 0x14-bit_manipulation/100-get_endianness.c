/**
 * get_endianness - A function that checks if the system's architecture
 * is little-endian or big-endian.
 *
 * Return: 1 if the system is little-endian, 0 if it is big-endian.
 */
int get_endianness(void)
{
    unsigned int num = 1;
    char *byte_ptr = (char *) &num;

    /* If the first byte is non-zero, the system is little-endian. */
    if (*byte_ptr)
        return 1;
    else
        return 0;
}

