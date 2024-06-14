#include <stdio.h>
#include <stdlib.h>

int main(void){
    int a, b;
    scanf("%d %d", &a, &b);
    int q;
    scanf("%d", &q);
    for(int i = 0; i < q; i++){
        int o;
        scanf("%d", &o);
        if(o == 1){
            int half = a / 2;
            a -= half;
            b += half;
        }else{
            int half = b / 2;
            b -= half;
            a += half;
        }
    }
    printf("%d\n", abs(a - b));
}