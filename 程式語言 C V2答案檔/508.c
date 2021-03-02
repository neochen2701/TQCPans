#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int i;
    char a[9], b[9];

    scanf("%s", a);
    scanf("%s", b);

    int avalue = 0, bvalue = 0;
    int power = 7;
    for (i = 0; i < 8; i++, power--)
    {
        if (a[i] == '1')
        {
            avalue += pow(2, power);
        }
        if (b[i] == '1')
        {
            bvalue += pow(2, power);
        }
    }
    int ansv = avalue + bvalue;
    printf("%d + %d = %d\n", avalue, bvalue, ansv);

    int ans[8];
    for (i = 7; i >= 0; i--)
    {
        if ((ansv - pow(2, i)) >= 0)
        {
            ansv = ansv - pow(2, i);
            ans[i] = 1;
        }
        else
        {
            ans[i] = 0;
        }
    }
    for (i = 7; i >= 0; i--)
        printf("%d", ans[i]);

    return 0;
}
