#include <stdio.h>
#include <stdlib.h>

int compute(int a[]);
int main()
{
	int i, arr[6], num;
	for (i = 0; i < 6; i++)
	{
		scanf("%d", &arr[i]);
	}
	num = compute(arr);
	printf("%d\n", num);
	return 0;
}

// ===================================================
// Please write your code in the specified function
// Do NOT change the function name, type of parameter
// ===================================================
int compute(int a[])
{
	int i, n=0;
	for (i = 0; i < 6; i++)
	{
		if (a[i] % 3 == 0)
		{
			n++;
		}
	}
	return n;
}
