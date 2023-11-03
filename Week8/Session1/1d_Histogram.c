#include <stdio.h>

// Function to print a histogram for an array
void printHistogram(int My_Array[], int length) {
    printf("%s%13s%17s\n", "Element", "Value", "Histogram");
    
    for (int i = 0; i < length; ++i) {
        printf("%7d%13d        ", i, My_Array[i]);
        for (int j = 1; j <= My_Array[i]; ++j) {
            printf("%c", '*');
        }
        printf("\n"); 
    }
}

int main() {
    // Initialize the array
    int My_Array[6] = {21, 3, 17, 9, 15, 11};
    
    // Call the function to print the histogram
    printHistogram(My_Array, 6);
    
    return 0;
}