#include <stdio.h>
#include <stdlib.h>

int main(){
	int a, b, ans1, ans2, ia, ib, temp;
	scanf("%d %d",&a,&b);
	ia = a;
	ib = b;
	while(temp = a % b){
		a = b;
		b = temp;
	}
	ans1 = b;
	ans2 = ia * ib / ans1;
	
	printf("%d\n", ans1);
	printf("%d\n", ans2);
}
