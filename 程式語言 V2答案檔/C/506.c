#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compute(int n);
int main(){
    int n,i;
    scanf("%d",&n);
    
    if(compute(n)==1){
        printf("-1");
    }
	else{
        for(i=2;i<=n;i++){
            while(n!=i){
                if(n%i==0){
                    printf("%d*",i);
                    n=n/i;
                }else{
                    break;
                }
            }
        }
        printf("%d",n);
    }
}

int compute(int n){
	int i;
    if(n==1){
        return 0;
    }
    for(i=2; i<=sqrt(n); i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}
