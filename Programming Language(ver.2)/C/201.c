#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i;
	scanf("%d", &i);

	if (i%2==0)
		printf("even\n", i);
	else
		printf("odd\n", i);
	
	return 0;
}

