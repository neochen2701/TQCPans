#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void){
    int n;
    scanf("%d", &n);
    char text[100];
    scanf("%s", text);

    int count = 0;
    for(int i = 0; i < n; i++){
        count += isupper(text[i]) > 0;
    }

    printf("%d\n", count);
}