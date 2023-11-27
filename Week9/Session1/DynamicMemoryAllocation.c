#include <stdio.h>
#include <stdlib.h>
int main()
{	int array_size;
	printf("\n Input the size of the array = ");
	scanf("%d", &array_size);
	printf("\n\n");
	int* vector = (int *) malloc (sizeof(int)*array_size);
    // Check if memory allocation is successful
    if (vector == NULL) {
        printf("Memory allocation failed.\n");
        return 1; // Exit the program with an error code
    }
	for (int i=0; i<array_size; i++){
		vector[i] = i*i;
		printf ("\nvector[%d] = %d\n", i , vector[i]);
    }
    // Don't forget to free the dynamically allocated memory
    free(vector);

    return 0;
}
