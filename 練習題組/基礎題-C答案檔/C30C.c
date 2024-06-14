#include <stdio.h>
#include <stdlib.h>

int main(){
    // 宣告一個二維陣列，具有 4 個長度為 4 的一維陣列。
    int arr[4][4];

    // 對陣列每個元素逐一讀取數值
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    int column;
    scanf("%d", &column);

    int result = 0;
    for(int i = 0; i < 4; i++){
        result += arr[i][column];
    }

    printf("%d\n", result);
}