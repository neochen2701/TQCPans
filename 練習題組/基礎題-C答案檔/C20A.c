#include <stdio.h>

int main(void){
    int score;
    scanf("%d", &score);
    if(score >= 60){
        printf("Passed");
    }else{
        printf("Failed");
    }
}