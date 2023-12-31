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