#include <stdio.h>
#include <stdlib.h>

int main(void){
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    int numbers[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &numbers[i]);
    }
    for(int i = 0; i < n; i++){
        int distA = abs(numbers[i] - a);
        int distB = abs(numbers[i] - b);
        if(distA < distB){
            printf("A");
        } else {
            printf("B");
        }
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}
