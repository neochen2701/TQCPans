#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int compute(char *, char *, char *);

int main () {
    char string[50]={}, upper[50]={}, lower[50]={};
    char *ptr = string, *up = upper, *low = lower;
    scanf("%s", string);
    
    int uplen = compute(ptr, up, low);
    printf("%s\n", up);
    printf("%s\n", low);
	printf("%d\n", uplen);
}

int compute(char *ptr, char *up, char *low)
{
	int i, j=0, k=0, sum=0;
	for (i=0 ; i<strlen(ptr) ; i++){
		if (ptr[i]>='A' && ptr[i]<='Z'){
			up[j] = ptr[i];
			j++;
			sum += 1;
		}
		else if (ptr[i]>='a' && ptr[i]<='z'){
			low[k] = ptr[i];
			k++;
		}
	}
	return sum;
}



