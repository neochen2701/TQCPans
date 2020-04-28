#include <stdio.h>
#include <stdlib.h>

int compute(int a[]);
int main()
{
    int a[3];
    int i;
    for (i = 0; i < 3; i++)
    {
        scanf("%d", &a[i]);
    }
	printf("%d\n", compute(a));
    return 0;
}

// ===================================================
// Please write your code in the specified function
// Do NOT change the function name, type of parameter
// ===================================================
int compute(int a[])
{
    int ans;
    switch (a[1])
    {
	    case 1:
	        ans = a[0] + a[2];
	        break;
	    case 2:
	        ans = a[0] * a[2];
	        break;
    }
    return ans;
}
