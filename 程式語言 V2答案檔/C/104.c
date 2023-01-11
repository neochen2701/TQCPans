#include <stdio.h>
#include <stdlib.h>

int main ()
{
	float a, b, total;
	scanf("%f %f", &a, &b);
	
	total = a+b;
	int total_2 = (total+0.005)*100;
	
	printf("total=%.2f", total_2/100.);
	return 0;
}
