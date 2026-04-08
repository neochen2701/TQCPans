#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number, r_int = 0, tmp, ori_int;
    scanf("%d", &number);
    ori_int = number;
    
    while( number!=0 ){
        tmp = number%10;
        r_int = (r_int*10)+ tmp;
        number /= 10;
    }
    
    if (ori_int == r_int){
    	printf("Yes\n");	
	}
    else{
    	printf("No\n");
	}
    return 0;
} 
