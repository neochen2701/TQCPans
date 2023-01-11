#include <stdio.h>
#include <stdlib.h>

int main () 
{
	int a, b, c;
	scanf("%d %d %d", &a, &b ,&c);
	printf("%d\n", 60 <= a && a < 100);
	printf("%.2f\n", (b+1)/10.);
	printf("%d\n", a >= c ? a : c);
 	return 0;
}
