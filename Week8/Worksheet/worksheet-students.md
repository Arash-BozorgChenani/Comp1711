# Week8 Exercises
## Bronze Level

### 1. Transpose of a Matrix: 

Write a program that initializes a [2][3] 2-d array. Call a function to transpose the matrix (2-d array). Finally, print the arrays both before and after the conversion.

### 2. Matrix Multiplication: 

Write a program that call a function to perform matrix multiplication for two matcies A and B with the dimensions [2][3] and [3][2], respectively.


## Silver Level
### 1. Average of Students Marks

Write a program that creates a [4][5] 2-d array with random marks in the range [0 25]. Each row represents a student, and each column is a task for a coursework (similar to the Procedural Programming module). The output needs to display:

1. The sum of obtained marks across the 5 tasks for each student by calling a function.
2. The average of total marks among all the students.

Hint: You can use `rand() % 26` and `srand(time(NULL))` to generate random marks in the given range.

### 2. 3-d array of marks:

Write a C code the creates a 3-d array with the [2][3][4] dimension with 2 semesters, 3 students and 4 modules. Call a function to create and initialize random marks in the range [70 100]. The print the marks for all students in both semesters.

## Gold Level

### 1. Create a 2-d array of bloodiron values from data.txt:

Write a C code that reads from the data.txt file from Week 7 and:
1. tokenizes the values and puts the data and bloodiron in two fields of a struct,
2. reads all the bloodiron values from the struct and organizes them into a 2-d array with 5 rows, where the
 bloodiron values in the range [11 11.9] are put in the first row, the ones in the range [12 12.9] in the second row, the ones in the range [13 13.9] in the third row, the ones in the range [14 14.9] in the fourth row, the ones in the range [15 15.9] in the fifth row,
3. avoids duplication of bloodiron values,
4. prints the 2-d array
