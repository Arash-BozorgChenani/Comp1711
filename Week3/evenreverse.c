#include <stdio.h>

int main() {
    int i = 20;
    while (i >= 0) {
        printf("%d ", i);
        i -= 2;
    }
    printf("\n");
    return 0;
}