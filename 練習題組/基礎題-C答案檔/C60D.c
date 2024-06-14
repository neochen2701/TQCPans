#include <stdio.h>
#include <stdlib.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))

int main(void){
    int n;
    scanf("%d", &n);

    int mx;
    scanf("%d", &mx); // 初始化 mx 為第一個數字
    for(int i = 1; i < n; i++){ // 從第二個數字開始迭代
        int a;
        scanf("%d", &a);
        mx = MAX(mx, a);
    }

    printf("%d\n", mx);
    return 0;
}
