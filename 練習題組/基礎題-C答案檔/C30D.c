#include <stdio.h>
#include <stdlib.h>

// 一個用來計算二維陣列有多少個 1 的函式，傳入二維陣列與二維陣列的 size。
int compute(int arr[4][4], int size){
    int count = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(arr[i][j] == 1){
                count += 1;
            }
        }
    }
    return count;
}

int main(){
    // 宣告一個二維陣列，具有 4 個長度為 4 的一維陣列。
    int arr[4][4];

    // 對陣列每個元素逐一讀取數值
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    int result = compute(arr, 4);
    printf("%d\n", result);
}