#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char word[3][21];
    char wordcmp[5][21];
    int num[3];
    int cmp, total = 0;
    int i, j, m, n;

    for (i = 0; i < 3; i++)
    {
        scanf("%s", &word[i]);
        scanf("%d", &num[i]);
    }

    for (j = 0; j < 5; j++)
    {
        scanf("%s", &wordcmp[j]);
    }

    for (m = 0; m < 3; m++)
    {
        for (n = 0; n < 5; n++)
        {
            cmp = strcmp(word[m], wordcmp[n]);
            if (cmp == 0)
            {
                total += num[m];
            }
        }
    }

    printf("%d\n", total);

    return 0;
}
