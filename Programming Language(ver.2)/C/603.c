#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, n,m;
    scanf("%d %d",&n,&m);
    int num[n][m]; 
    
    for (i = 0; i < n; i++){
    	for(j = 0; j < m; j++){
    		scanf("%d", &num[i][j]);
		}
    }  
    
    for (i = 0; i < n; i++){
    	for(j = 0; j < m; j++){
    		if(j != m-1){
    			printf("%d,", num[i][j]);
			}else{
				printf("%d", num[i][j]);
			}
		}
		if(i != n-1){
			printf("\n");
		}
    }
    return 0;
}

