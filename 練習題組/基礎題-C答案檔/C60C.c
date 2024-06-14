#include <stdio.h>

int main(void){
    int h, w;
    scanf("%d %d", &h, &w);

    int arr[h][w];

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    for(int i = 0; i < h; i++){
        int count = 0;
        for(int j = 0; j < w; j++){
            count += arr[i][j];
        }
        printf("%d", count);
        if(i != h - 1){
            printf(" ");
        }
    }
    printf("\n");
    for(int i = 0; i < w; i++){
        int count = 0;
        for(int j = 0; j < h; j++){
            count += arr[j][i];
        }
        printf("%d", (int) (count / ((double) (h)) + 0.5));
        if(i != w - 1){
            printf(" ");
        }
    }
}