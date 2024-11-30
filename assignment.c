#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

// Check if a string is a positive integer

int is_positive_integer(const char *str) {
    while (*str) {
        if (!isdigit(*str)) {
            return 0; // Not a number
        }
        str++;
    }
    return 1;
}

int main(int argc, char *argv[]) {

    srand(time(NULL));

    // Check if the correct number of arguments is provided

    if (argc != 3) {
        printf("Incorrect usage. You provided %d arguments. The correct number of arguments is 2\n", argc - 1);
        return 1;
    }

    // Check if arguments are positive integers

    if (!is_positive_integer(argv[1]) || !is_positive_integer(argv[2])) {
        printf("Incorrect usage. The parameters you provided are not positive integers\n");
        return 1;
    }

    // Arguments to integers

    int rows = atoi(argv[1]);
    int cols = atoi(argv[2]);

    // Create matrix
    
    int matrix[rows][cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = (rand() % 100) + 1; // Random number between 1 and 100
        }
    }

    // Write  matrix to matrix.txt

    FILE *file = fopen("matrix.txt", "w");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(file, "%d", matrix[i][j]);
            if (j < cols - 1) {
                fprintf(file, " "); // Add a space between numbers
            }
        }
        fprintf(file, "\n"); // Newline at the end of each row
    }

    fclose(file);

    return 0;
}
