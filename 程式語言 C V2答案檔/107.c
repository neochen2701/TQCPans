#include <stdio.h>
#include <stdlib.h>

int main ()
{
	int a, b, c, d, e, f;
	scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);

	printf("%10d %10d %10d\n", a, b, c);
	printf("%10d %10d %10d\n", d, e, f);

	printf("%-10d %-10d %-10d\n", a, b, c);
	printf("%-10d %-10d %-10d\n", d, e, f);

	return 0;
}



