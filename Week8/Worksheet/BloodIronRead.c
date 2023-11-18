#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define NUM_ROWS 5
#define NUM_COLUMNS 71

struct BloodironEntry {
    char date[20];
    double bloodiron;
};

int readAndTokenize(const char *filename, struct BloodironEntry *entries, int maxEntries) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening the file for reading.\n");
        return -1;
    }

    int numEntries = 0;
    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL && numEntries < maxEntries) {
        sscanf(line, "%19[^,],%lf", entries[numEntries].date, &entries[numEntries].bloodiron);
        numEntries++;
    }

    fclose(file);
    return numEntries;
}

void processBloodirons(const struct BloodironEntry *entries, int numEntries, double bloodironArray[NUM_ROWS][NUM_COLUMNS], int *rowSizes) {
    for (int i = 0; i < NUM_ROWS; ++i) {
        rowSizes[i] = 0;
    }

    for (int i = 0; i < numEntries; ++i) {
        double bloodiron = entries[i].bloodiron;
        int row = -1;

        if (bloodiron >= 11.0 && bloodiron < 12.0) {
            row = 0;
        } else if (bloodiron >= 12.0 && bloodiron < 13.0) {
            row = 1;
        } else if (bloodiron >= 13.0 && bloodiron < 14.0) {
            row = 2;
        } else if (bloodiron >= 14.0 && bloodiron < 15.0) {
            row = 3;
        } else if (bloodiron >= 15.0 && bloodiron < 16.0) {
            row = 4;
        }

        // Check if the value is not already present in the current row
        int duplicate = 0;
        for (int j = 0; j < rowSizes[row]; ++j) {
            if (bloodironArray[row][j] == bloodiron) {
                duplicate = 1;
                break;
            }
        }

        if (!duplicate) {
            bloodironArray[row][rowSizes[row]++] = bloodiron;
        }
    }
}

void printArray(const double bloodironArray[NUM_ROWS][NUM_COLUMNS], const int *rowSizes) {
    for (int i = 0; i < NUM_ROWS; ++i) {
        for (int j = 0; j < rowSizes[i]; ++j) {
            printf("%.1f ", bloodironArray[i][j]);
        }
        printf("\n");
    }
}

int main() {
    const char *filename = "data.txt";
    struct BloodironEntry entries[NUM_COLUMNS];
    double bloodironArray[NUM_ROWS][NUM_COLUMNS];
    int rowSizes[NUM_ROWS];

    int numEntries = readAndTokenize(filename, entries, NUM_COLUMNS);

    if (numEntries > 0) {
        processBloodirons(entries, numEntries, bloodironArray, rowSizes);
        printArray(bloodironArray, rowSizes);
    }

    return 0;
}
