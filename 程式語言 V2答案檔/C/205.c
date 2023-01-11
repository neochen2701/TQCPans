#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int i,  num;
	int num1=0, num2=0, num3=0, num4=0, num5=0, num6=0, others=0;

	for (i=1; i<=10; i++) {
		scanf("%d", &num);
		switch (num) {
		    case 1:
				num1++;
				break;
		    case 2:
				num2++;
				break;
		    case 3:
				num3++;
				break;
		    case 4:
				num4++;
				break;
            case 5:
				num5++;
				break;
            case 6:
				num6++;
				break;
		    default:
				others++;
		}
		
	}
	printf("number1:%d\nnumber2:%d\nnumber3:%d\nnumber4:%d\nnumber5:%d\nnumber6:%d\nerror:%d\n",
			   num1, num2, num3, num4, num5, num6, others);
    return 0;
}
