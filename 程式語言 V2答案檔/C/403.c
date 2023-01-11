#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main ()
{
	int i; 
 	char arr[100];
    scanf("%s",arr);
    for(i=0; arr[i]!='\0'; i++){
        if(arr[i]>='A' && arr[i]<='Z')
            arr[i] = tolower(arr[i]);
        else if(arr[i]>='a' && arr[i]<='z')
            arr[i] = toupper(arr[i]);
    }
    printf("%s\n",arr);
    return 0;
}

