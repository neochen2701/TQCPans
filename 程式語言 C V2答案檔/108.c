#include <stdio.h>
#include <stdlib.h>

int main ()
{
    const double pi = 3.1415;
    int d;
	double r,area;

	scanf("%d", &d);
    r = d / 2.0;
	area = r * r * pi;
	
	int r_2 = (r+0.005)*100;
	int area_2 = (area+0.00005)*10000;

    printf("%-10d\n", d);
    printf("%-10.2f\n", r_2/100.);
	printf("%-10.4f\n", area_2/10000.);

 	return 0;
}




