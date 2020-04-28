#include <stdio.h>
#include <stdlib.h>

int main () 
{
	char ans[4] , num[3][4];
    int i, j, A=0, B=0;
    
    scanf("%s", ans);

    for (i=0 ; i<3 ; i++)
    	scanf("%s", num[i]);

	for (i=0 ; i<3 ; i++){
		A = 0;
		B = 0;
		for (j=0 ; j<4 ; j++){
	        if (num[i][j] == ans[j])
	            A++;
	        else if(j==0){
	            if (num[i][j]==ans[1] || num[i][j]==ans[2] || num[i][j]==ans[3])
	                B++;
	        }
	        else if(j==1){
	            if (num[i][j]==ans[0] || num[i][j]==ans[2] || num[i][j]==ans[3])
	                B++;
	        }
	        else if(j==2){
	            if (num[i][j]==ans[0] || num[i][j]==ans[1] || num[i][j]==ans[3])
	                B++;
	        }
	        else if(j==3){
	            if (num[i][j]==ans[0] || num[i][j]==ans[1] || num[i][j]==ans[2])
	                B++;
	        }
	    }
	    printf("%dA%dB\n", A, B);
	}
    return 0;
}
