#include <stdio.h>
int main() {
    float width, height, area;
    // Prompt user for the dimensions​

    printf("Enter the width of the rectangle: ");
    scanf("%f", &width);
    printf("Enter the height of the rectangle: ");
    scanf("%f", &height);

    // Calculate the area​
    area = width * height;

    // Output the result​
    printf("The area of the rectangle is: %.2f\n", area);
    return 0;
}