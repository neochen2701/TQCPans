#include <stdio.h>
#include <stdlib.h>

int main ()
{
	char string[10];
	int output;
	scanf("%s", string);
	output=atoi(string);
	printf("%s change to %d\n", string, output);
	return 0;
}


