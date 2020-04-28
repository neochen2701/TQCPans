#include <stdio.h>
#include <stdlib.h>

int main ()
{
	int unit;
	double price=23.34;
	double total;
	scanf("%d", &unit);
	total = unit*price;
	printf("%.2f", total);
	return 0;
}
