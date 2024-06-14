#include <stdio.h>

int main(){
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    double result = a + b + c;
    printf("%.3lf", result);
}