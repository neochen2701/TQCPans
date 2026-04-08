#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ()
{
    int i;
    int a,b,c;
    double ans;

    scanf("%d %d",&a,&b);

    for(i = 1;i < a;i++){
        c = sqrt(i);
        ans = c + 0.0;
        if(sqrt(i) == ans){
            printf("%.0lf\n",pow(c,b));
        }
    }
    return 0;
}

