#include <stdio.h>

int main(void){
    int w, h;
    scanf("%d %d", &w, &h);

    int arr1[w][h];
    int arr2[w][h];

    for(int i = 0; i < w; i++){
        for(int j = 0; j < h; j++){
            scanf("%d", &arr1[i][j]);
        }
    }
    for(int i = 0; i < w; i++){
        for(int j = 0; j < h; j++){
            scanf("%d", &arr2[i][j]);
        }
    }
    for(int i = 0; i < w; i++){
        for(int j = 0; j < h; j++){
            printf("%d", arr1[i][j] + arr2[i][j]);
            if(j != h - 1){
                printf(" ");
            }
        }
        printf("\n");
    }
}