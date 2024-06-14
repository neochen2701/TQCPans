#include <stdio.h>
#include <stdlib.h>

int main(void){
    int n;
    scanf("%d", &n);
    int arr[n];
    int arr_index[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &arr_index[i]);
    }
    int temp = 0;
    for(int i = 0; i < n; i++){
        int a = arr[arr_index[i]];
        if(a <= temp){
            printf("No\n");
            return 0;
        }
        temp = a;
    }
    printf("Yes\n");
}