#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
	int n, m, i, j;
	scanf("%d %d", &n, &m);
	int grid[n+2][m+2];
	memset(grid, 0 ,sizeof(grid));
	
	for(i = 1; i <= n; i++){
		for(j = 1; j <= m; j++){
			scanf("%d", &grid[i][j]);
		}
	}
	for(i = 1; i <= n; i++){
		for(j = 1; j <= m; j++){
			if(grid[i][j] == 0)
				printf(" ");
			else{
				if(grid[i+1][j] == 0 || grid[i][j+1] == 0 || grid[i-1][j] == 0 || grid[i][j-1] == 0)
					printf("*");
				else
					printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
