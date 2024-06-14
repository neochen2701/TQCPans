#include <stdio.h>

int main(void){
    int n;
    scanf("%d", &n);
    char text[100];
    scanf("%s", text);

    for(int i = 0; i < n / 2; i++){
        if(text[i] != text[n-i-1]){
            printf("No\n");
            return 0;
        }
    }

    printf("Yes\n");
    return 0;
}