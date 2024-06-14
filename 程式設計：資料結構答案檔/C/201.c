#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100

int tasks[MAX_TASKS];
int taskCount = 0;

int RequestQuests(char input[]) {
    char *token = strtok(input, ",");
    while (token != NULL) {
        int taskReward = atoi(token);
        if (taskReward >= 0) {
            tasks[taskCount++] = taskReward;
        } else {
            printf("error\n");
            return 0;
        }
        token = strtok(NULL, ",");
    }
    return 1;
}

int CalculateTotalReward() {
    int totalReward = 0;
    int morningTasks = 3;
    int noonTasks = 2;
    int nightTasks = 1;

    for (int i = 0; i < taskCount; ) {
        for (int j = 0; j < morningTasks && i < taskCount; j++, i++) {
            totalReward += tasks[i] * 3;
        }

        for (int j = 0; j < noonTasks && i < taskCount; j++, i++) {
            totalReward += tasks[i] * 2;
        }

        for (int j = 0; j < nightTasks && i < taskCount; j++, i++) {
            totalReward += tasks[i];
        }
    }

    return totalReward;
}

int main() {
    char input[256];
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;

    if (RequestQuests(input)) {
        int totalReward = CalculateTotalReward();
        printf("%d\n", totalReward);
    }

    return 0;
}
