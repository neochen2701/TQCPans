#include <stdio.h>
#include <stdlib.h>

double compute(int a[]);
int main (){
	double ans;
	int i,a[6];
	for(i = 0;i < 6; i++) {
        scanf("%d", &a[i]);
	}
	ans = compute(a);
	printf("%.3lf\n", ans);

	return 0;
}

// ===================================================
// Please write your code in the specified function
// Do NOT change the function name, type of parameter
// ===================================================
double compute(int a[])
{
	double min = 10.0;
	int i;
	for(i = 0;i < 3;i++){
    	if((double)a[i] / a[i+3] < min){
    		min =  (double)a[i] / a[i+3];
       }
	}
	return min;
}

