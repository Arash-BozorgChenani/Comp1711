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
