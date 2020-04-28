#include <stdio.h>
#include <stdlib.h>

int main ()
{
	int num1, num2;
    char operand;

	scanf("%d%d ", &num1, &num2);
	scanf("%c", &operand);
	
	switch (operand) {
		case '+':
			printf("%d+%d=%d\n", num1, num2, num1+num2);
			break;
		case '-':
			printf("%d-%d=%d\n", num1, num2, num1-num2);
			break;
		case '*':
			printf("%d*%d=%d\n", num1, num2, num1*num2);
			break;
 		default:
			printf("error\n");
	}
    return 0;
}
