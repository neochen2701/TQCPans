#include<stdio.h>
#include<stdlib.h>

int main(){
	int score;
	
	scanf("%d", &score);
	
	if(60 <= score && score <= 100){
		printf("pass\n");
		if(score % 2 == 0){
			printf("even");
		}
		else{
			printf("odd");
		}
	}
	else if(score > 100 || score < 0 ){
		printf("error");
	}
	else{
		printf("fail\n");
		if(score % 2 == 0){
			printf("even");
		}
		else{
			printf("odd");
		}
	}
}
