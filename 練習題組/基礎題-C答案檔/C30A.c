#include <stdio.h>

int diffabs(int a, int b){
    if(a > b){
        return a - b;
    }else{
        return b - a;
    }
}

int main(){
    int a, b;
    scanf("%d %d", &a , &b);
    int result = diffabs(a, b);
    printf("%d", result);
}