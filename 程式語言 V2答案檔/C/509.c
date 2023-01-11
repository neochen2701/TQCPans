#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char string[128];
	char *delim = "/";
	char *pch;
	int num[64], sum = 0, i, n;

	scanf("%s", string);

	pch = strtok(string, delim);
	i = 0;
	while (pch != NULL)
	{
		num[i++] = atoi(pch);
		sum += num[i - 1];
		pch = strtok(NULL, delim);
	}

	n = i;
	for (i = 0; i < n; i++)
	{
		if (i != 0)
			printf(" ");
		printf("%d", num[i]);
	}
	printf("\n");
	printf("%d\n", sum);
	return 0;
}
