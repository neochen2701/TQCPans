#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ()
{
	int x1, y1, x2, y2; 
    scanf("%d", &x1);
    scanf("%d", &y1);
    scanf("%d", &x2);
    scanf("%d", &y2);
    
    double x = pow(x1-x2, 2);
	double y = pow(y1-y2, 2);
	
	double result = sqrt(x+y);
	int result_2 = (result+0.005)*100;
	
	printf("%.2f", result_2/100.);
 	return 0;
}
