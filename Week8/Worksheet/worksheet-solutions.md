# Week8 Exercises
## Bronze Level

### 1. Transpose of a Matrix: 

Write a program that initializes a [2][3] 2-d array. Call a function to transpose the matrix (2-d array). Finally, print the arrays both before and after the conversion.

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

### 2. Matrix Multiplication: 

Write a program that call a function to perform matrix multiplication for two matcies A and B with the dimensions [2][3] and [3][2], respectively.

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

### 2. 3-d array of marks:

Write a C code the creates a 3-d array with the [2][3][4] dimension with 2 semesters, 3 students and 4 modules. Call a function to create and initialize random marks in the range [70 100]. The print the marks for all students in both semesters.

```c
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>   

#define SEMESTERS 2  // Number of semesters
#define STUDENTS 3   // Number of students
#define SUBJECTS 4   // Number of subjects

// Function to generate a random mark in the range [70, 100]
int generateRandomMark() {
    return rand() % 31 + 70;
}

// Function to initialize the 3D array with random marks
void initializeMarksArray(int marksArray[SEMESTERS][STUDENTS][SUBJECTS]) {
    // Seed the random number generator
    srand((unsigned int)time(NULL));

    // Initialize the 3D array with random values in the range [70, 100]
    for (int semester = 0; semester < SEMESTERS; ++semester) {
        for (int student = 0; student < STUDENTS; ++student) {
            for (int subject = 0; subject < SUBJECTS; ++subject) {
                marksArray[semester][student][subject] = generateRandomMark();
            }
        }
    }
}

int main() {

    int marksArray[SEMESTERS][STUDENTS][SUBJECTS];
    initializeMarksArray(marksArray);

    // print values from the 3D array
    for (int semester = 0; semester < SEMESTERS; ++semester) {
        printf("Semester %d:\n", semester + 1);
        for (int student = 0; student < STUDENTS; ++student) {
            printf("  Student %d: ", student + 1);
            for (int subject = 0; subject < SUBJECTS; ++subject) {
                printf("%d ", marksArray[semester][student][subject]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}

```

## Gold Level

### 1. Create a 2-d array of bloodiron values from data.txt:
Write a C code that reads from the data.txt file from Week 7 and:
1. tokenizes the values and puts the data and bloodiron in two fields of a struct,
2. reads all the bloodiron values from the struct and organizes them into a 2-d array with 5 rows, where the
 bloodiron values in the range [11 11.9] are put in the first row, the ones in the range [12 12.9] in the second row, the ones in the range [13 13.9] in the third row, the ones in the range [14 14.9] in the fourth row, the ones in the range [15 15.9] in the fifth row,
3. avoids duplication of bloodiron values,
4. prints the 2-d array

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define NUM_ROWS 5
#define NUM_COLUMNS 71

struct BloodironEntry {
    char date[20];
    double bloodiron;
};

int readAndTokenize(const char *filename, struct BloodironEntry *entries, int maxEntries) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening the file for reading.\n");
        return -1;
    }

    int numEntries = 0;
    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL && numEntries < maxEntries) {
        sscanf(line, "%19[^,],%lf", entries[numEntries].date, &entries[numEntries].bloodiron);
        numEntries++;
    }

    fclose(file);
    return numEntries;
}

void processBloodirons(const struct BloodironEntry *entries, int numEntries, double bloodironArray[NUM_ROWS][NUM_COLUMNS], int *rowSizes) {
    for (int i = 0; i < NUM_ROWS; ++i) {
        rowSizes[i] = 0;
    }

    for (int i = 0; i < numEntries; ++i) {
        double bloodiron = entries[i].bloodiron;
        int row = -1;

        if (bloodiron >= 11.0 && bloodiron < 12.0) {
            row = 0;
        } else if (bloodiron >= 12.0 && bloodiron < 13.0) {
            row = 1;
        } else if (bloodiron >= 13.0 && bloodiron < 14.0) {
            row = 2;
        } else if (bloodiron >= 14.0 && bloodiron < 15.0) {
            row = 3;
        } else if (bloodiron >= 15.0 && bloodiron < 16.0) {
            row = 4;
        }

        // Check if the value is not already present in the current row
        int duplicate = 0;
        for (int j = 0; j < rowSizes[row]; ++j) {
            if (bloodironArray[row][j] == bloodiron) {
                duplicate = 1;
                break;
            }
        }

        if (!duplicate) {
            bloodironArray[row][rowSizes[row]++] = bloodiron;
        }
    }
}

void printArray(const double bloodironArray[NUM_ROWS][NUM_COLUMNS], const int *rowSizes) {
    for (int i = 0; i < NUM_ROWS; ++i) {
        for (int j = 0; j < rowSizes[i]; ++j) {
            printf("%.1f ", bloodironArray[i][j]);
        }
        printf("\n");
    }
}

int main() {
    const char *filename = "data.txt";
    struct BloodironEntry entries[NUM_COLUMNS];
    double bloodironArray[NUM_ROWS][NUM_COLUMNS];
    int rowSizes[NUM_ROWS];

    int numEntries = readAndTokenize(filename, entries, NUM_COLUMNS);

    if (numEntries > 0) {
        processBloodirons(entries, numEntries, bloodironArray, rowSizes);
        printArray(bloodironArray, rowSizes);
    }

    return 0;
}

```