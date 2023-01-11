#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
    FILE * input;
    char str[1024];
    int a[3];
    int i;
    for(i = 0;i < 3;i++)
        scanf("%d",&a[i]);

    input = fopen("read.txt","rt");

    for(i = 0;!feof(input);i++){
        if(fgets(str,sizeof(str),input) != NULL){
            memset(str,a[i] + '0',a[i]);
            printf(str);
        }
    }
    fclose(input);
    return 0;
}
