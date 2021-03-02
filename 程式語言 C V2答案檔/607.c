#include <stdio.h>
#include <stdlib.h>

int main()
{
	char a[4], b[4];
	char poker[5] = "CDHS";
	int a_poker, a_num, b_poker, b_num, i;

	scanf("%s %s", a, b);

	for (i = 0; i < 4; i++)
	{
		if (a[0] == poker[i])
			a_poker = i + 1;
	}
	if (a[2] == 0)
		a_num = a[1] - 48;
	else
		a_num = (a[1] - 48) * 10 + (a[2] - 48);

	for (i = 0; i < 4; i++)
	{
		if (b[0] == poker[i])
			b_poker = i + 1;
	}
	if (b[2] == 0)
		b_num = b[1] - 48;
	else
		b_num = (b[1] - 48) * 10 + (b[2] - 48);

	if (a_poker > b_poker)
	{
		printf("%s > %s\n", a, b);
	}
	else if (a_poker < b_poker)
	{
		printf("%s < %s\n", a, b);
	}
	else
	{
		if (a_num > b_num)
		{
			printf("%s > %s\n", a, b);
		}
		else if (a_num < b_num)
		{
			printf("%s < %s\n", a, b);
		}
		else
		{
			printf("%s = %s\n", a, b);
		}
	}

	return 0;
}
