#include <stdio.h>
#include <stdlib.h>

int compute(int n);
int main () 
{
    int num, i, ans[10];
    scanf("%d", &num);
    for(i = 0; i < num; i++){
    	ans[i] = compute(i + 1);
	}
    for(i--; i >= 0; i--){
    	printf("fib(%d)=%d\n", i + 1, ans[i]);
	}
	return 0;
}

// ===================================================
// Please write your code in the specified function
// Do NOT change the function name, type of parameter
// ===================================================
int compute(int n)
{
	if(n <= 2) return 1;
	else return compute(n-1) + compute(n-2);
}
