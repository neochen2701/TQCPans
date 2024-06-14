#include <stdio.h>

int main() {
    // Open the file for reading
    FILE *file = fopen("read.txt", "r");

    // Check if the file was opened successfully
    if (file == NULL) {
        fprintf(stderr, "Error opening file: read.txt\n");
        return 1; // Return an error code
    }

    // Read and output the content of the file
    int c;
    while ((c = fgetc(file)) != EOF) {
        putchar(c);
    }

    // Close the file
    fclose(file);

    return 0; // Return success
}