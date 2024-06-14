#include <stdio.h>
#include <stdlib.h>

int main(){
    int arr[5];
    
    for(int i = 0; i < 5; i++){
        scanf("%d", &arr[i]);
    }
    
    int result = 0;
    for(int i = 0; i < 5; i++){
        result += arr[i];
    }
    
    printf("%d", result);
}