#include <stdio.h>
#include <stdlib.h>

int main(void){
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        int a;
        scanf("%d", &a);

        printf("%d", abs(a));
        if(i != n-1){
            printf(" ");
        }
    }
}