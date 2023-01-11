#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int i, j, count;
    scanf("%d", &count);

    for (i=2; i<count; i++){
        int isPrime = 1;
        for (j=2; j<i; j++){
            if (i % j == 0){
                isPrime = 0;
                break;
            }
        }

        if (isPrime == 1){
            printf("%d ", i);
        }
    }
    
    return 0;
}
