#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
        if (i < n - 1)
        {
            printf(" ");
        }
    }
    printf("\n");

    for (int i = 0; i < n; i++)
    {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }
        if (!swapped)
        {
            break;
        }
        for (int k = 0; k < n; k++)
        {
            printf("%d", arr[k]);
            if (k < n - 1)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int input_numbers[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &input_numbers[i]);
    }
    bubble_sort(input_numbers, n);

    return 0;
}
