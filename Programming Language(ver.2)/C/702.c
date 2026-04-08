#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main(){
	char num[10];
	int sum, power, i;
	scanf("%s", num);
	power = strlen(num) - 1;
	for(i = 0, sum = 0; i < strlen(num); i++, power--){
		if(num[i] == '1'){
			sum += pow(2, power);
		}
	}
	printf("%d\n", sum);
    return 0;
}
