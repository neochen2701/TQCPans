#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Monster {
    int Value;
    struct Monster* Next;
} Monster;

Monster* createMonster(int value) {
    Monster* newMonster = (Monster*)malloc(sizeof(Monster));
    if (newMonster == NULL) {
        exit(1); // Allocation failed
    }
    newMonster->Value = value;
    newMonster->Next = NULL;
    return newMonster;
}

void addMonster(Monster** head, int value) {
    Monster* newNode = createMonster(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Monster* current = *head;
        while (current->Next != NULL) {
            current = current->Next;
        }
        current->Next = newNode;
    }
}

void createMonsters(Monster** head, const char* input) {
    char* token = strtok((char*)input, ",");
    while (token != NULL) {
        int monsterAttack = atoi(token);
        addMonster(head, monsterAttack);
        token = strtok(NULL, ",");
    }
}

int simulateBattle(Monster* head, int playerHP) {
    Monster* current = head;
    int level = 1;

    while (current != NULL) {
        playerHP -= current->Value;

        if (playerHP <= 0) {
            printf("game over! dead at level %d\n", level);
            return 0;
        }

        level++;
        current = current->Next;
    }

    printf("game clear! hp left %d\n", playerHP);
    return 1;
}

void freeMonsters(Monster* head) {
    while (head != NULL) {
        Monster* temp = head;
        head = head->Next;
        free(temp);
    }
}

int main() {
    char input[256];
    if (fgets(input, sizeof(input), stdin) == NULL) {
        printf("input error\n");
        return 1;
    }

    // Remove newline character if present
    input[strcspn(input, "\n")] = 0;

    Monster* head = NULL;
    createMonsters(&head, input);

    int playerHP = 100;
    simulateBattle(head, playerHP);

    freeMonsters(head);

    return 0;
}
