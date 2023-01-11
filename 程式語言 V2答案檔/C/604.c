#include <stdio.h>
#include <stdlib.h>

int compute(int arr[]);
int main()
{
    int i;
    int arr[9];
    for (i = 0; i < 9; i++){
        scanf("%d", &arr[i]);
    }
    printf("sum = %d\n", compute(arr));
    return 0;
}

int compute(int arr[])
{   
    int i, j, index, temp;
    int sum = 0;

    for (i = 0; i < 9; i++)
    {
        index = i;
        for (j = i+1; j < 9; j++)
        {
            if (arr[j] < arr[index])
            {
                index = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
        
        printf("%d\n",arr[i]);
        sum += arr[i];
    }

    return sum;
}
