#include <stdio.h>

int main(void){
    int hour;
    scanf("%d", &hour);
    if(hour < 12){
        printf("Morning");
    }else if(hour <= 18){
        printf("Afternoon");
    }else if(hour <= 23) {
        printf("Evening");
    }
    return 0;
}