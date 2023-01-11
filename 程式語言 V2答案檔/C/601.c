#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char compute(char *ptr, int n);

int main () {
    char string[10];
    scanf("%s", string);
    char *ptr = string;
    int n;
    scanf("%d", &n);
    
    printf("The letter that was selected is: %c\n",compute(ptr, n));
	printf("%s\n", ptr);
}

char compute(char *ptr, int n)
{
    if(ptr[n]>='A' && ptr[n]<='Z')
        ptr[n] = tolower(ptr[n]);
    else if(ptr[n]>='a' && ptr[n]<='z')
    	ptr[n] = toupper(ptr[n]);
    return ptr[n];
}
