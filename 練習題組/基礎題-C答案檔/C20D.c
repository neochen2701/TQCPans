#include <stdio.h>

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    int result = 0;
    for(int i = 0; i < a; i++){
        if(i % b == 0){
            result += i;
        }
    }
    printf("%d", result);
}