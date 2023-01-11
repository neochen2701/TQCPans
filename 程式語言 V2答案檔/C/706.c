#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr;
    int num;
    int arr[10];
    int count = 0;
    fptr = fopen("read.txt", "r");

    while(fscanf(fptr, "%d", &num) != EOF){
        arr[count] = num;
        count++;
    }
    
	int i,j;
    for(i=0; i<4; i++,count++){
        scanf("%d", &arr[count]);
    }

    for(i=0; i<count; i++){
        for(j=i+1; j<count; j++){
            if(arr[i] > arr[j]){
                double tmp;
                tmp=arr[i];
                arr[i]=arr[j];
                arr[j]=tmp;
            }
        }
    }

    FILE *fp;
    fp = fopen("write.txt", "w");
    if(fptr){
        for(i=0; i<count; i++){
          printf("%d\n", arr[i]);
          fprintf(fp,"%d\n", arr[i]);
       }
    }
}
