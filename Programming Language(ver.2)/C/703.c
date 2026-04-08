#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
	int money, fifty=0, ten=0, five=0, one=0;

	scanf("%d", &money);

	while (money>=50){
		money-=50;
		fifty++;
	}
	while (money>=10){
		money-=10;
		ten++;
	}
	while (money>=5){
		money-=5;
		five++;
	}
	one = money;


	if (fifty > 0){
		printf("%d*$50", fifty);
	}

	if (ten > 0){
		if (fifty>0)
			printf(" ");
		printf("%d*$10", ten);
	}
	if(five > 0){
		if (fifty>0 || ten>0)
			printf(" ");
		printf("%d*$5", five);
	}
	if(one > 0){
		if (fifty>0 || ten>0 || five>0)
			printf(" ");
		printf("%d*$1", one);
	}
    return 0;
}
