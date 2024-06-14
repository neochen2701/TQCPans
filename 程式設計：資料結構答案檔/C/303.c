#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ORDERS 20
#define MAX_LENGTH 100
#define MAX_ITEMS 5
#define MAX_WORDS 10
#define MAX_COMBINATIONS 10

void generate_combinations(char *items[], char *combinations[MAX_COMBINATIONS][2], int *num_combinations)
{
    *num_combinations = 0;
    for (int i = 0; i < MAX_ITEMS; i++)
    {
        for (int j = i + 1; j < MAX_ITEMS; j++)
        {
            if (strcmp(items[i], items[j]) <= 0)
            {
                combinations[*num_combinations][0] = items[i];
                combinations[*num_combinations][1] = items[j];
            }
            else
            {
                combinations[*num_combinations][0] = items[j];
                combinations[*num_combinations][1] = items[i];
            }
            (*num_combinations)++;
        }
    }
}
int isInOrder(char *item, char *order[], int count)
{
    for (int i = 0; i < count; i++)
    {
        if (strcmp(item, order[i]) == 0)
            return 1;
    }
    return 0;
}
void compute(char *order[], int count, int relations[MAX_COMBINATIONS], char *combinations[MAX_COMBINATIONS][2], int num_combinations)
{
    for (int i = 0; i < num_combinations; i++)
    {
        if (isInOrder(combinations[i][0], order, count) && (isInOrder(combinations[i][1], order, count)))
        {
            relations[i]++;
        }
    }
}
int isSmall(char *s1[2], char *s2[2])
{
    if (strcmp(s1[0], s2[0]) < 0)
        return 1;
    else if ((strcmp(s1[0], s2[0]) == 0) && (strcmp(s1[1], s2[1]) < 0))
        return 1;
    return 0;
}
void sort_and_index(int relations[MAX_COMBINATIONS], char *combinations[MAX_COMBINATIONS][2], int num_combinations)
{
    for (int i = 0; i < num_combinations - 1; i++)
    {
        for (int j = 0; j < num_combinations - i - 1; j++)
        {
            if ((relations[j] < relations[j + 1]) || ((relations[j] == relations[j + 1]) && (isSmall(combinations[j], combinations[j + 1]))))
            {
                int temp = relations[j];
                relations[j] = relations[j + 1];
                relations[j + 1] = temp;
                char *temp_comb[2];
                temp_comb[0] = combinations[j][0];
                temp_comb[1] = combinations[j][1];
                combinations[j][0] = combinations[j + 1][0];
                combinations[j][1] = combinations[j + 1][1];
                combinations[j + 1][0] = temp_comb[0];
                combinations[j + 1][1] = temp_comb[1];
            }
        }
    }
    int limit = (num_combinations < 3) ? num_combinations : 3;
    for (int i = 0; i < limit; i++)
    {
        printf("%s %s %d\n", combinations[i][0], combinations[i][1], relations[i]);
    }
}
void split(char data[], char *order[], int *c)
{
    int len = strlen(data);
    if (data[len - 1] == '\n')
        data[len - 1] = '\0';
    (*c) = 0;
    order[(*c)++] = data;
    for (int i = 0; i < len; i++)
    {
        if (data[i] == ' ')
        {
            data[i] = '\0';
            order[(*c)++] = &data[i + 1];
        }
    }
}

void check()
{
    char *items[] = {"apple", "watermelon", "pawpaw", "banana", "pineapple"};
    char *combinations[MAX_COMBINATIONS][2];
    int relations[MAX_COMBINATIONS] = {0};
    int num_combinations;
    int n;
    char data[MAX_ORDERS][MAX_LENGTH];
    char *orders[MAX_ORDERS][MAX_ITEMS];
    int count[MAX_ORDERS];
    generate_combinations(items, combinations, &num_combinations);
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++)
    {
        fgets(data[i], MAX_LENGTH, stdin);
        split(data[i], orders[i], &count[i]);
        compute(orders[i], count[i], relations, combinations, num_combinations);
    }
    sort_and_index(relations, combinations, num_combinations);
}

int main()
{
    check();
    return 0;
}
