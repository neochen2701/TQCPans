#include <stdio.h>

int main() {
    // 打開檔案以供讀取
    FILE *file = fopen("read.txt", "r");

    // 檢查檔案是否成功開啟
    if (file == NULL) {
        return 1; // 返回錯誤碼
    }

    // 讀取檔案中的長字串
    char longString[1000]; // 假設字串不會超過1000個字元
    if (fgets(longString, sizeof(longString), file) == NULL) {
        fclose(file); // 關閉檔案
        return 1; // 返回錯誤碼
    }

    // 讀取檔案中的索引值
    int targetIndex;
    if (fscanf(file, "%d", &targetIndex) != 1) {
        fclose(file); // 關閉檔案
        return 1; // 返回錯誤碼
    }

    // 關閉檔案
    fclose(file);

    // 檢查索引值是否在有效範圍內
    if (targetIndex < 0 || targetIndex >= sizeof(longString) - 1) {
        return 1; // 返回錯誤碼
    }

    // 初始化計數器
    int count = 0;

    // 取得指定索引值對應的字元
    char targetChar = longString[targetIndex];

    // 遍歷字串，計算目標字元出現的次數
    for (int i = 0; longString[i] != '\0'; i++) {
        if (longString[i] == targetChar) {
            count++;
        }
    }

    // 顯示結果
    printf("%d\n", count);

    return 0; // 返回成功碼
}
