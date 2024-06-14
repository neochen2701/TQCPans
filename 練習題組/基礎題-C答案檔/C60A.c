#include <stdio.h>

int main(void){
    int a;
    scanf("%d", &a);

    switch(a){
        case 1:
            printf("red #FF0000");
            break;
        case 2:
            printf("green #00FF00");
            break;
        case 3:
            printf("blue #0000FF");
            break;
        case 4:
            printf("yellow #FFFF00");
            break;
        case 5:
            printf("white #FFFFFF");
            break;
        case 6:
            printf("cyan #00FFFF");
            break;
        case 7:
            printf("magenta #FF00FF");
            break;
    }
}