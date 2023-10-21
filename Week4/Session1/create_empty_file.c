#include <stdio.h>

int main () {
    char filename [] = "data.csv";
    FILE *myfile = fopen (filename, "w"); // or "a", "w+", "a+"
    if (myfile == NULL) {
        perror("");
        return 1;
    }

    fclose(myfile);
    return 0;
}