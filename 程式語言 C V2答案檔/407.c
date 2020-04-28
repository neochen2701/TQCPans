#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE * input;
    FILE * output;

    char * delim = "*";
    char * ptr_c;
    char str[1024];

    input = fopen("read.txt","rt");

    fgets(str,sizeof(str),input);
    ptr_c = strtok(str,delim);

    output = fopen("write.txt","wt");
    while(ptr_c != NULL){
        fprintf(output,"%s",ptr_c);
        ptr_c = strtok(NULL,delim);
    }
    
    fclose(input);
    fclose(output);
    return 0;
}
