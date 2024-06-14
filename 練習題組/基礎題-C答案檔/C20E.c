#include <stdio.h>

int main(){
    int a, b;
    do {
        scanf("%d %d", &a, &b);
    } while(a == b);

    if (a > b){
        printf("Yes");
    }else{
        printf("No");
    }
}