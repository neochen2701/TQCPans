#include <stdio.h>
#include <stdlib.h>

int main () 
{
	int i = 0, j, num, mul, ans = 1;
	int a[10];
	scanf("%d", &num);
	
	if (num == 0){
		printf("0=0\n");
	}
	else {
		while (num > 0){
			mul = num % 10;
			ans *= mul;
			num = num/10;
			a[i] = mul;
			i++;
		}
		for (j=i-1 ; j>=0 ; j--){
			printf("%d", a[j]);
			if (j != 0)
				printf("*");
		}
		printf("=%d\n", ans);
	}
	return 0;
}
