#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct  triangle
{
    int side1;
    int side2;
    int side3;
};

double compute(struct triangle *ptri);
int main ()
{
    struct triangle *ptri;
    ptri = malloc(sizeof(struct triangle));
    scanf("%d", &ptri->side1);
    scanf("%d", &ptri->side2);
    scanf("%d", &ptri->side3);
    double area = compute(ptri);
    printf("%.2f\n", area);
    free(ptri);
    return 0;
}

double compute(struct triangle *ptri)
{
    double s,area;
    s = ( ptri->side1 + ptri->side2 + ptri->side3) / 2.0;
    area = sqrt( s * (s-ptri->side1) * (s-ptri->side2) * (s-ptri->side3));
    return area;
}
