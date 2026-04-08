#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compute(int n);

int main()
{
	int n;
	scanf("%d", &n);
	if (n > 0 && n < 1000)
	{
		printf("%d\n", compute(n));
	}
	else
	{
		printf("error\n");
	}
}

// ===================================================
// Please write your code in the specified function
// Do NOT change the function name, type of parameter
// ===================================================
int compute(int n)
{
	int i;
	int x = 0;
	for (i = 1; i < n; i++)
	{
		int count = 1;
		int num = 0;
		int tmp = i;
		while (tmp > 9)
		{
			count++;
			tmp /= 10;
		}
		tmp = i;
		while (tmp)
		{
			num += (int)(pow(tmp % 10, count) + 0.5);
			tmp /= 10;
		}
		if (num == i)
		{
			printf("%d\n", i);
			x += i;
		}
	}
	return x;
}
