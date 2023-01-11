#include <stdio.h>
#include <stdlib.h>

int main () 
{
    int floor; 
	
	scanf("%d", &floor);
	switch (floor) {
		case 1:
			printf("one\n");
			break;
		case 2:
			printf("two\n");
			break;
		case 3:
			printf("three\n");
			break;
		case 4:
			printf("four\n");
			break;
		default:
			printf("error\n");
	}
    return 0;
}
