#include <stdio.h>

/**
- * main - prints the fist 98 fibonacci numbers, starting with 1 and 2
 *
 * Return: Always 0.
 */


int main()
{
    int a = 1, b = 2, c, i;
    
    printf("%d, %d, ", a, b);
    
    for(i = 2; i < 98; i++)
    {
        c = a + b;
        printf("%d, ", c);
        a = b;
        b = c;
    }
    printf("%d\n", a+b);
    
    return 0;
}

