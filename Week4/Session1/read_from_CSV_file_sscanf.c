#include <stdio.h>
#include <string.h>

int main() {
    char filename [] = "data.csv";
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("");
        return 1;
    }

    char buffer[100];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        char name[8], timeslot[10];
        int age;
        sscanf(buffer, "%[^,], %d, %[^,\n]", name, &age, timeslot);
        printf("Name: %s\tAge: %d\t\tTimeslot: %s\n", name, age, timeslot);
    }

    fclose(file);
    return 0;
}