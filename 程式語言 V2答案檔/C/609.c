#include <stdio.h>
#include <stdlib.h>

int main() {
	int i;
	int arr[12]={31, 28, 31, 30 , 31, 30, 31, 31, 30, 31, 30, 31};
    int y , m , d ;
    
    scanf("%d %d %d", &y, &m, &d);
	int check ;
    if(y % 4 == 0 && y % 100 != 0 || y % 400 == 0){
        check = 1;
    } else {
        check = 0;
    }
    
    if((y<0) || (m<1 || m>12) || (d<1)){
        printf("error\n");
        return 0;
    }
    if( check==0 && d>arr[m-1] ||		  //�D�|�~ && ��j���몺�� 
		check==1 && m!=2 && d>arr[m-1] || //�|�~ && ���O�G�� && ��j���몺��
		check==1 && m==2 && d>29) {		  //�|�~ && �O�G��A�B��j��29 
    	printf("error\n");
        return 0;
	}
    
    int date = d ;
    
    for(i=m-2; i>-1; i--){
        date +=arr[i];
    }
    if(check==1 && m>=3){
        date++;
    }
    printf("%d\n", date);
    return 0;
}
