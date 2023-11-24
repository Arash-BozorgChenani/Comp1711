#include <stdio.h>

int main()
{
    int vector[5] = {11,13,17,23,31};
    int* address = vector;

    printf ("\n Address[0] = %d\n\n", *address);
    printf ("\n Address[0] = %d\n\n", *address++);
    printf ("\n Address[2] = %d\n\n", *++address);
    printf ("\n What is happening here?\n");
}