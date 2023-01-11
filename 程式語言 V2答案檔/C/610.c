#include<stdio.h>
#include<stdlib.h>

int main(){
	int a1, b1, a2, b2, i ,j;
	scanf("%d %d", &a1, &b1);
	int grid1[a1][b1];
	for(i = 0; i < a1; i++){
		for(j = 0; j < b1; j++){
			scanf("%d", &grid1[i][j]);
		}
	}
	scanf("%d %d", &a2, &b2);
	int grid2[a2][b2];
	for(i = 0; i < a2; i++){
		for(j = 0; j < b2; j++){
			scanf("%d", &grid2[i][j]);
		}
	} 
	if(b1 != a2){
		printf("error\n");
	}
	else{
		int answer[a1][b2], sum, k;
		for(i = 0; i < a1; i++){
			for(j = 0; j < b2; j++){
				for(sum = k = 0; k < b1; k++){
					sum += grid1[i][k] * grid2[k][j];
				}
				answer[i][j] = sum;
			}
		}
		for(i = 0; i < a1; i++){
			for(j = 0; j < b2; j++){
				if(j != 0) printf(" ");
				printf("%d", answer[i][j]);
			}
			printf("\n");
		}
	}
    return 0;
}
