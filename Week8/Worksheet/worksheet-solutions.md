# Week8 Exercise
## Bronze Level

### 1. Transpose of a Matrix: Write a program that initializes a [2][3] 2-d array. Call a function to transpose the matrix (2-d array). Finally, print the arrays both before and after the conversion.

```c
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
```

### 2. Matrix Multiplication: Write a program that call a function to perform matrix multiplication for two matcies A and B with the dimensions [2][3] and [3][2], respectively.

```c
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
```

## Silver Level
### 1. Average of Students Marks

Write a program that creates a [4][5] 2-d array with random marks in the range [0 25]. Each row represents a student, and each column is a task for a coursework (similar to the Procedural Programming module). The output needs to display:

1. The sum of obtained marks across the 5 tasks for each student by calling a function.
2. The average of total marks among all the students.

Hint: You can use `rand() % 26` and `srand(time(NULL))` to generate random marks in the given range.

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to calculate the sum of marks for each student
void calculateSumOfMarks(int matrix[][5], int numStudents, int numTasks, int sumOfMarks[]) {
    for (int i = 0; i < numStudents; i++) {
        int totalMark = 0;
        for (int j = 0; j < numTasks; j++) {
            totalMark += matrix[i][j];
        }
        sumOfMarks[i] = totalMark;
    }
}

int main() {
    const int NUM_STUDENTS = 4;
    const int NUM_TASKS = 5;

    // Seed the random number generator
    srand(time(NULL));

    // Generate a 3x5 matrix with random numbers in the range [0, 25]
    int matrix[NUM_STUDENTS][NUM_TASKS];
    for (int i = 0; i < NUM_STUDENTS; i++) {
        for (int j = 0; j < NUM_TASKS; j++) {
            matrix[i][j] = rand() % 26; // Generate a random number in the range [0, 25]
        }
    }

    int sumOfMarks[NUM_STUDENTS];

    // Calculate the sum of marks for each student using the function
    calculateSumOfMarks(matrix, NUM_STUDENTS, NUM_TASKS, sumOfMarks);

    // Display the sum of marks for each student
    printf("Sum of Marks for Each Student:\n");
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("Student %d: %d\n", i + 1, sumOfMarks[i]);
    }

    // Calculate the overall average of marks for all students based on the sum of marks
    float overallAverage = 0.0;
    for (int i = 0; i < NUM_STUDENTS; i++) {
        overallAverage += sumOfMarks[i];
    }
    overallAverage /= NUM_STUDENTS;

    printf("\nOverall Average of Marks for All Students: %.2f\n", overallAverage);

    return 0;
}
```

## Gold Level
### 1.