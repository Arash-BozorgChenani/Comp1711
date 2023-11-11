#include <stdio.h>

// Function to multiply two matrices
void multiplyMatrices(int A[][3], int B[][2], int result[][2], int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Function to print a matrix
void printMatrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrixA[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int matrixB[3][2] = {{9, 8}, {6, 5}, {3, 2}};
    int result[2][2];

    multiplyMatrices(matrixA, matrixB, result, 2, 3, 2);

    printf("Matrix A:\n");
    printMatrix(2, 3, matrixA);

    printf("\nMatrix B:\n");
    printMatrix(3, 2, matrixB);

    printf("\nResultant Matrix (A * B):\n");
    printMatrix(2, 2, result);

    return 0;
}