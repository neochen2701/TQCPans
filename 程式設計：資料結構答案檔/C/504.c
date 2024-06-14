#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10000
typedef struct order_s
{
    int order_number;
    int time;
    int value;
} Order;
typedef struct validate_s
{
    Order order[SIZE];
    int size;
    int value;
} Validate;

void getOrdersFromFile(Order orders[], int *n, int *available_time)
{
    scanf("%d", n);
    for (int i = 0; i < *n; i++)
    {
        scanf("%d", &orders[i].order_number);
        scanf("%d", &orders[i].time);
        scanf("%d", &orders[i].value);
    }
    scanf("%d", available_time);
}

void printAnswer(const Validate v)
{
    for (int i = 0; i < v.size; i++)
    {
        if (i > 0)
        {
            printf(" ");
        }
        printf("%d", v.order[i].order_number);
    }
    printf("\n%d\n", v.value);
}

int compare(const void *a, const void *b)
{
    Order *p1 = (Order *)a, *p2 = (Order *)b;
    return (p1->order_number - p2->order_number);
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

void optimal_order_selection(Order *orders, int n, int available_time, int **dp)
{
    for (int i = 1; i <= n; i++)
    {
        int order_number = orders[i - 1].order_number;
        int time = orders[i - 1].time;
        int value = orders[i - 1].value;
        for (int j = 0; j <= available_time; j++)
        {
            if (time > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - time] + value);
            }
        }
    }
}
Validate find_selected_orders(Order *orders, int n, int available_time, int **dp)
{
    Validate v;
    v.size = 0;
    v.value = 0;
    int i = n;
    int j = available_time;
    while (i > 0 && j > 0)
    {
        if (dp[i][j] != dp[i - 1][j])
        {
            v.order[v.size++] = orders[i - 1];
            v.value += orders[i - 1].value;
            j -= orders[i - 1].time;
        }
        i--;
    }
    return v;
}
void dynamicProg(Order orders[], int n, int available_time)
{
    int **dp = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++)
    {
        dp[i] = (int *)malloc((available_time + 1) * sizeof(int));
        for (int j = 0; j <= available_time; j++)
        {
            dp[i][j] = 0;
        }
    }
    optimal_order_selection(orders, n, available_time, dp);
    Validate v = find_selected_orders(orders, n, available_time, dp);
    qsort(v.order, v.size, sizeof(Order), compare);
    printAnswer(v);
    for (int i = 0; i <= n; i++)
        free(dp[i]);
    free(dp);
}

void test()
{
    int n, available_time;
    Order orders[SIZE];
    getOrdersFromFile(orders, &n, &available_time);
    dynamicProg(orders, n, available_time);
}

int main()
{
    test();
    return 0;
}