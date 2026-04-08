#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int i, j, total=0;
    scanf("%d", &i);
    scanf("%d", &j);
    
    if(i%2 == 0)
    {
        i+=1;
    }

    for(;i<=j;i+=2)
    {
        total += i;
    }
    printf("%d\n", total);
    return 0;
}
