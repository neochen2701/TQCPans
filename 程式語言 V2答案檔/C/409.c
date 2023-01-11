#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main () 
{
    FILE *fptr, *fptr2;
	fptr = fopen("read.txt", "r");
	fptr2 = fopen("write.txt", "w");
	char str[256];
	
	int len, i, k, flag;
	while(fgets(str, 256, fptr) != NULL){
		len = strlen(str);
		for(i = 0; i < len; i++){
			flag = 0;
			if(isalpha(str[i])){
				k = str[i] - 'a';
				if(k + 2 <= 25){
					str[i] = k + 2 + 'a';
				}
				else{
					str[i] = (k + 2) % 26 + 'a';
				}
			}
		}
		fprintf(fptr2, "%s", str);
	}
	fclose(fptr);
	fclose(fptr2);
	return 0;
}
