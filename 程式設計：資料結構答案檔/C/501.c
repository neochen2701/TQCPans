#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int **create2DArray(int rows, int cols) {
    int **arr = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        arr[i] = (int *)malloc(cols * sizeof(int));
    }
    return arr;
}

void free2DArray(int **arr, int rows) {
    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);
}

void getActivitiesFromInput(int **activities, int num_activities) {
    int start, end;
    for (int i = 0; i < num_activities; i++) {
        scanf("%d,%d", &start, &end);
        activities[i][0] = start;
        activities[i][1] = end;
    }
}

void sortActivities(int **activities, int num_activities) {
    for (int i = 0; i < num_activities - 1; i++) {
        for (int j = i + 1; j < num_activities; j++) {
            if (activities[i][1] > activities[j][1]) {
                int tempStart = activities[i][0];
                int tempEnd = activities[i][1];
                activities[i][0] = activities[j][0];
                activities[i][1] = activities[j][1];
                activities[j][0] = tempStart;
                activities[j][1] = tempEnd;
            }
        }
    }
}

int main() {
    int num_activities;
    scanf("%d", &num_activities);

    int **activities = create2DArray(num_activities, 2);

    getActivitiesFromInput(activities, num_activities);
    sortActivities(activities, num_activities);

    int select = 1;
    int *curr_act = activities[0];
    for (int i = 1; i < num_activities; i++) {
        if (curr_act[1] <= activities[i][0]) {
            curr_act = activities[i];
            select++;
        }
    }

    printf("%d\n", select);

    free2DArray(activities, num_activities);
    return 0;
}
