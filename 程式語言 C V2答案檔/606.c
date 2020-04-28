#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, a, b;
    char id[3][6], verify[3];

	for (i=0 ; i<3 ; i++){
		scanf("%s", id[i]);
	}
	
    for (i=0 ; i<3 ; i++){    
        a = id[i][0]+id[i][2]+id[i][4] - 48*3;
        b = (id[i][1]+id[i][3] - 48*2)*5;
        verify[i] = (a+b) % 26;

        if (verify[i] == id[i][5] - 64){
            printf("Pass\n");
        }
        else
            printf("Fail\n");
    }
    
    return 0;
}

