#include <stdio.h>
#include <stdlib.h>

int main () {

	int i,j,a,sum=0;
	scanf("%d",&a);

	switch(a){
    case 0:
        for(i=1;i<6;i++){
            for(j=1;j<6;j++){
                sum = i * j;
                printf("%d x %d = %d\t",i,j,sum);
            }
            printf("\n");
        }
        break;
    case 1:
           for(i=1;i<6;i++){
            for(j=1;j<6;j++){
                sum = i * j;
                printf("%d x %d = %d\t",j,i,sum);
            }
            printf("\n");
        }
        break;
    default:
        printf("error\n");
        break;
	}

    return 0;
}
