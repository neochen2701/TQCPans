#include <stdio.h>
#include <stdlib.h>

char compute(int s[]);
int main()
{
    int box[2];
    scanf("%d", &box[0]);
    scanf("%d", &box[1]);
    printf("%d\n", compute(box));
    return 0;
}

// ===================================================
// Please write your code in the specified function
// Do NOT change the function name, type of parameter
// ===================================================
char compute(int box[])
{
    int x, y;
    for (y = 0; y < box[1]; y++)
    {
        for (x = 0; x < box[0]; x++)
        {
            printf("*");
        }
        printf("\n");
    }
    return box[0] * box[1];
}
