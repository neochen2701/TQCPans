#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compute(char str[]);
int main ()
{
    char str1[20];
    char str2[20];
    char str3[40];
    scanf("%s", str1);
    scanf("%s", str2);

    if((int)strlen(str1) <= 3 || (int)strlen(str2) <= 3 || (int)strlen(str1) > 20 || (int)strlen(str2) > 20)
    {
        printf("error\n");
    }
    else
    {
        printf("%d\n", (int)strlen(str1));
        printf("%d\n", (int)strlen(str2));
        
		strcpy(str3, str1);
        strcat(str3, str2);
        compute(str3);
    }
    return 0;
}

void compute(char str[])
{
    int i=0,j=0;
    while(str[i]!='\0')
    {
        i++;
    }
    for(j=i-1; j>=0; j--)
    {
        printf("%c",str[j]);
    }

}
