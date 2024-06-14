#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int scores[50];
    int num_scores;
    int sum;
    double avg;
} Student;

int read_input(Student **students) {
    int capacity = 10;
    *students = (Student *)malloc(capacity * sizeof(Student));
    int count = 0;
    char line[256];
    while (1) {
        fgets(line, 256, stdin);
        if (strncmp(line, "END\0", 4) == 0) break;
        if (strncmp(line, "END\n", 4) == 0) break;
        if (count >= capacity) {
            capacity *= 2;
            *students = (Student *)realloc(*students, capacity * sizeof(Student));
        }
        char *token = strtok(line, " ");
        strcpy((*students)[count].name, token);
        int scoreIndex = 0;
        while (token != NULL) {
            token = strtok(NULL, " ");
            if (token != NULL) {
                (*students)[count].scores[scoreIndex++] = atoi(token);
            }
        }
        (*students)[count].num_scores = scoreIndex;
        count++;
    }
    return count;
}

void calculate_sum_avg(Student *students, int count) {
    for (int i = 0; i < count; i++) {
        int sum = 0;
        for (int j = 0; j < students[i].num_scores; j++) {
            sum += students[i].scores[j];
        }
        students[i].sum = sum;
        students[i].avg = (double)sum / students[i].num_scores;
    }
}

int compare_students(const void *a, const void *b) {
    Student *studentA = (Student *)a;
    Student *studentB = (Student *)b;
    return (studentB->avg - studentA->avg) > 0 ? 1 : -1;
}

int main() {
    Student *students;
    int count = read_input(&students);
    calculate_sum_avg(students, count);
    qsort(students, count, sizeof(Student), compare_students);
    for (int i = 0; i < count; i++) {
        printf("%s ", students[i].name);
        for (int j = 0; j < students[i].num_scores; j++) {
            printf("%d ", students[i].scores[j]);
        }
        printf("%d %.2f\n", students[i].sum, students[i].avg);
    }
    free(students);
    return 0;
}
