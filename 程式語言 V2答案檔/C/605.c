#include <stdio.h>
#include <stdlib.h>

int compute(int *);

int main ( )
{
    int arr[6];
    int final, i;
    for (i=0; i<6; i++){
        scanf("%d", &arr[i]);
    }

    final=compute(arr);
    printf("%d\n", final);
    return 0;
}

int compute(int *p)
{
	int totala=0, totalb=0, tot=0;
	int index, temp;
    int i, j, k;

    for (i = 5; i > 0; i--){
        for (j = 0; j <= i-1; j++){
            if (*(p+j) < *(p+j+1)){
		        temp = *(p+j);
		        *(p+j) = *(p+j+1);
		        *(p+j+1) = temp;
            }
        }
    }

    for(k = 0; k < 3; k++){
    	totala+=*(p+k);
    	totalb+=*(p+k+3);
	}
	if(totala > totalb){
		tot = totala - totalb;
	}
	else{
		tot = totalb - totala;
	}

    return tot;
}
