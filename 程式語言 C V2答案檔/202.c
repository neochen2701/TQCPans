#include <stdio.h>
#include <stdlib.h>

int main() 
{
	int score, adjust;
	scanf("%d", &score);
	if( 0 <= score && score <= 100){
		if (score > 60)
		    adjust = score+10;
		else 
		    adjust = score+5;
		printf("%d\n", adjust);
	}
	else{
		printf("error\n");
	}
	return 0;
}
