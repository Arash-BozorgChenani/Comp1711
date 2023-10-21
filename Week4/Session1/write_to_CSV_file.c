#include <stdio.h>

int main() {
    char filename [] = "data.csv";
    FILE *file = fopen(filename, "w"); // or "a", "w+", "a+"
    if (file == NULL) {
        perror("");
        return 1;
    }

    fprintf(file, "Alice, 25, Tue 11:00\n");
    fprintf(file, "Bob,   30, Mon 13:00\n");
    fprintf(file, "Carl,  22, Tue 09:00\n");

    fclose(file);
    return 0;
}