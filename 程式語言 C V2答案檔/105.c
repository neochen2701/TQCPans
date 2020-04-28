#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ()
{
    int i, j;
	float result;
	
	scanf("%d%d",&i, &j);
	result = sqrt(i+j);
	int result_2 = (result+0.005)*100;
	
	printf("result=%.2f\n", result_2/100.);
   	return 0;
}
