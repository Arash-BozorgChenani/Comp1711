#include<stdio.h>
int main() {
    int i = 1;  // Start from the first natural number
    while (i <= 10) {
        int square = i * i;  // Calculate the square of i
        printf("%d ", square);
        i++;  // Increment i to move to the next natural number
    }
    printf("\n");
    return 0;
}