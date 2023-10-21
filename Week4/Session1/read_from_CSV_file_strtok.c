#include <stdio.h>
#include <string.h>

int main() {
    char filename [] = "data.csv";
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("");
        return 1;
    }

    char line_buffer[100];
    while (fgets(line_buffer, sizeof(line_buffer), file) != NULL) {
        char *token = strtok(line_buffer, ",");
        while (token) {
            printf("%s, ", token);
            token = strtok(NULL, ",");
        }
        printf("\n");
    }

    fclose(file);
    return 0;
}