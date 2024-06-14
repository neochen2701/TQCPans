#include <stdio.h>

int main() {
    // Open the source file for reading
    FILE *sourceFile = fopen("read.txt", "r");

    // Check if the source file was opened successfully
    if (sourceFile == NULL) {
        fprintf(stderr, "Error opening source file: read.txt\n");
        return 1; // Return an error code
    }

    // Open the destination file for writing
    FILE *destinationFile = fopen("write.txt", "w");

    // Check if the destination file was opened successfully
    if (destinationFile == NULL) {
        fprintf(stderr, "Error opening destination file: write.txt\n");
        fclose(sourceFile); // Close the source file
        return 1; // Return an error code
    }

    // Read from the source file and write to the destination file
    int c;
    while ((c = fgetc(sourceFile)) != EOF) {
        fputc(c, destinationFile);
    }

    // Close both files
    fclose(sourceFile);
    fclose(destinationFile);

    return 0; // Return success
}
