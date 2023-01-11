#include <stdio.h>
#include <stdlib.h>

int main ()
{
	int a, b, c;
	double total;
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);

	total = a+b+c;	
	int average = ((total/3)+0.005)*100;
	
	printf("%d+%d+%d=%.0f\n", a, b, c,total);
	printf("%.2f", average/100.);
	return 0;
}
