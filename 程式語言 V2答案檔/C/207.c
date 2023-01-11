#include <stdio.h>
#include <stdlib.h>

int main(){
	int num, i, conut=0;
	scanf("%d",&num);
	
	for(i = 2 ;i <= num;i++){
		if((num % i) == 0)
            conut++;
	}
	
	if(conut == 1)
        printf("%d is a prime number",num);
    else
        printf("%d is not a prime number",num);
    return 0;
}

