#include <stdio.h>

int main(void){
    int n;
    scanf("%d", &n);

    int count = 0;
    for(int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        count += (a+1) % 2;
    }
    
    printf("%d", count);
}