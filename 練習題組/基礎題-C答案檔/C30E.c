#include <stdio.h>
#include <stdlib.h>

// 用於計算二維陣列每欄的總合是否等於 compare 一維陣列。
int compute(int arr[3][3], int compare[3]){
    for(int column = 0; column < 3; column++){
        int sum = 0;
        for(int i = 0; i < 3; i++){
            sum += arr[i][column];
        }
        if(sum != compare[column]){
            return 0;
        }
    }
    return 1;
    // 使用巢狀迴圈來遍歷，先以欄當作遍歷目標
    // 宣告一個 sum 變數用於儲存該欄的數值總合
    // 使用巢狀迴圈來遍歷，先以列當作遍歷目標
    // 將數值加到 sum 上
    // 此處應有大括號
    // 比較該欄是否等於 compare 對應的欄位的數值，如果不等於則直接 return false
    // 此處應有大括號
    // 因為所有元素都遍歷完了，可直接 return true
}

int main(){
    int arr[3][3];
    int compare[3];

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    for(int i = 0; i < 3; i++){
        scanf("%d", &compare[i]);
    }

    int result = compute(arr, compare);

    if(result){
        printf("Yes");
    }else{
        printf("No");
    }
}