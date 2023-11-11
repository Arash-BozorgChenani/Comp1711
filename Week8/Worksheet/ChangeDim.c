#include <stdio.h>

// Function to change the dimensions of the array
void changeDimensions(int original[][3], int changed[][2]) {
    // Copy values from the original array to the changed array
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            changed[j][i] = original[i][j];
        }
    }
}

int main() {
    // Original [2][3] array
    int originalArray[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    // Display the original array
    printf("Original Array [2][3]:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%3d ", originalArray[i][j]);
        }
        printf("\n");
    }

    int changedArray[3][2];

    changeDimensions(originalArray, changedArray);

    // Display the changed array
    printf("\nChanged Array [3][2]:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%3d ", changedArray[i][j]);
        }
        printf("\n");
    }

    return 0;
}