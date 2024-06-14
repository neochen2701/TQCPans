#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 1000
#define MAX_NAME_LENGTH 50

typedef struct {
    int Id;
    char Name[MAX_NAME_LENGTH];
    int Level;
    int Score;
} Player;

int comparePlayers(const void *a, const void *b) {
    Player *player1 = (Player *)a;
    Player *player2 = (Player *)b;

    return player2->Score - player1->Score;
}

void readCsvFile(const char* filePath, Player players[], int* count) {
    FILE* file = fopen(filePath, "r");
    if (!file) {
        printf("Error opening file\n");
        return;
    }

    char line[256];
    fgets(line, sizeof(line), file);

    while (fgets(line, sizeof(line), file) && *count < MAX_PLAYERS) {
        Player p;
        if (sscanf(line, "%d,%49[^,],%d,%d", &p.Id, p.Name, &p.Level, &p.Score) == 4) {
            players[(*count)++] = p;
        }
    }

    fclose(file);
}

void displaySortedPlayerData(Player players[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d | %d | %s | %d | %d\n", i + 1, players[i].Id, players[i].Name, players[i].Level, players[i].Score);
    }
}

int main() {
    Player players[MAX_PLAYERS];
    int count = 0;
    readCsvFile("read.csv", players, &count);

    int n;
    scanf("%d", &n);

    if (n > count) {
        printf("Exceeds data upper limit\n");
    } else {
        qsort(players, count, sizeof(Player), comparePlayers);
        displaySortedPlayerData(players, n);
    }

    return 0;
}
