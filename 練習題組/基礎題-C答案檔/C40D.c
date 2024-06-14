#include <stdio.h>

int main() {
    // 打開檔案以供讀取
    FILE *file = fopen("read.txt", "r");

    // 檢查檔案是否成功開啟
    if (file == NULL) {
        return 1;
    }

    // 定義變數來儲存讀取的兩個數字
    int num1, num2;

    // 從檔案中讀取兩個數字
    if (fscanf(file, "%d %d", &num1, &num2) != 2) {
        fclose(file); 
        return 1; 
    }

    // 計算兩數的總和
    int sum = num1 + num2;

    // 顯示結果
    printf("%d\n", sum);

    // 關閉檔案
    fclose(file);

    return 0; // 返回成功碼
}
