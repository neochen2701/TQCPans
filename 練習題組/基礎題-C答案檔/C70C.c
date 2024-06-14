#include <stdio.h>

int main(void){
    int w, n;
    scanf("%d %d", &w, &n);
    int count = 0;
    for(int i = 0; i < n; i++){
        int transaction;
        scanf("%d", &transaction);
        if(transaction < 0){
            if(w + transaction < 0){  // 餘額不足，需儲值
                count++;
                w = 0;  // 餘額補足到足夠支付此次交易
            } else {
                w += transaction;
            }
        } else {
            count++;  // 正數交易即為儲值
            w += transaction;
        }
    }
    printf("%d\n", count);
    return 0;
}
