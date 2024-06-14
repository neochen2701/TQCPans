#include <stdio.h>

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    int count = 0;
    int tmp = a;
    while(tmp < b){
        tmp *= a;
        count += 1;
    }
    printf("%d", count);
}