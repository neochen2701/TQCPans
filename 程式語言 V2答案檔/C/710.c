#include<stdio.h>
#include<stdlib.h>

typedef struct Frame{
    int frame;
    int myTime;
}FRAME;

void FIFO(FRAME * frame,int * page){
    int i = 0,j = 0,k = 0;
    int sw = 10;
    int index=0;

    for(i = 0;i < 10;i++){
        j = 0;
        while(page[i] != -1){
            if(frame[j].frame == 0){
                frame[j].frame = page[i];
                frame[j].myTime = i;
                page[i] = -1;
            }else if(frame[j].frame == page[i]){
                page[i] = -1;
            }else if(j == 3){
                for(k = 0;k < 4;k++){
                    if(frame[k].myTime < sw){
                        sw = frame[k].myTime;
                        index = k;
                    }
                }
                frame[index].frame = page[i];
                frame[index].myTime = i;
                page[i] = -1;
                sw = 10;
            }
            j++;
        }
        for(j = 0;j < 4;j++){
            printf("%-2d",frame[j].frame);
        }
        printf("\n");
    }

}


int main(){
	int i,page[10],s;
	for(i = 0;i < 10;i++)
        scanf("%d",&page[i]);

	FRAME frame[4];
	for(i = 0;i < 4;i++)
        frame[i].frame = 0;

    FIFO(frame,page);

    return 0;
}
