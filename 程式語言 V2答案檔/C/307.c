#include <stdio.h>
#include <stdlib.h>

int compute(int a[]);
int main()
{
    int arr[5], i, maximum;
    
    for(i=0; i<5; i++)
        scanf("%d", &arr[i]);

    maximum = compute(arr);
    printf("%d\n", maximum);
    return 0;
}

// ===================================================
// Please write your code in the specified function
// Do NOT change the function name, type of parameter
// ===================================================
int compute(int a[])
{
    int k, M;
    M=a[0];
    for(k=0; k<5; k++)
        if (a[k]>M)
            M=a[k];
    return M;
}
