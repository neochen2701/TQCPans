#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () 
{
    char big[] = "QWERTYUIOPPASDFGHJKLLZXCVBNMM";
    char small[] = "qwertyuioppasdfghjkllzxcvbnmm";
 	char str[50]={}, str2[50]={};
 	int i, j;

	scanf("%s", str);
	
    for (i=0 ; i<strlen(str) ; i++){
        if (str[i]>='A' && str[i]<='Z'){
            for (j=0 ; j<strlen(big) ; j++){
                if (str[i] == big[j]){
                	str2[i] = big[j+1];
                	break;
				}
				
            }
        }
        else if (str[i]>='a' && str[i]<='z'){
            for (j=0 ; j<strlen(big) ; j++){
                if (str[i] == small[j]){
                	str2[i] = small[j+1];
                	break;
				}
            }
        }
    }
    
	printf("%s\n", str2);
	return 0;
}
