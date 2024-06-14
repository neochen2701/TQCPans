#include <stdio.h>

int main(void) {
    int a, count = 0, number;
    FILE *file;

    scanf("%d", &a);

    file = fopen("read.txt", "r");
    if (file == NULL) {
        printf("Unable to open file.\n");
        return 1;
    }

    while (fscanf(file, "%d", &number) != EOF) {
        if (number > a) {
            count++;
        }
    }
    fclose(file);
    printf("%d\n", count);
    return 0;
}
