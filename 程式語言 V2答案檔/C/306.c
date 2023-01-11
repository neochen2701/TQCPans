#include <stdio.h>
#include <stdlib.h>

int compute(int num);

int main()
{
	int num;
	scanf("%d", &num);
	printf("%d!=%d", num, compute(num));
	return 0;
}

// ===================================================
// Please write your code in the specified function
// Do NOT change the function name, type of parameter
// ===================================================
int compute(int num)
{
	if( num == 0 )
        return 1;
    if( num >= 1 )
        return num*compute(num-1);
}

