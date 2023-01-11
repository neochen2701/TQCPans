#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ()
{
	double result;
	double a, b, c, d, e, f;
	scanf("%lf %lf %lf", &a, &b, &c);
	scanf("%lf %lf %lf", &d, &e, &f);
	
	result = fabs(a)*floor(b)+pow(c, d)*sqrt(e)+log10(f);
	int result_2 = (result+0.005)*100;
	
	printf("%.2f\n", result_2/100.);
    return 0;
} 
