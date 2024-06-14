#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main(void) {
    int n1, n2;
    scanf("%d %d", &n1, &n2);

    int *A = (int *)calloc(n1 + 1, sizeof(int));
    int *B = (int *)calloc(n2 + 1, sizeof(int));

    for (int i = 1; i <= n1; i++) {
        scanf("%d", &A[i]);
    }
    for (int j = 1; j <= n2; j++) {
        scanf("%d", &B[j]);
    }

    int *DP = (int *)calloc(n2 + 1, sizeof(int));

    for (int i = 1; i <= n1; i++) {
        int *temp = (int *)calloc(n2 + 1, sizeof(int));
        for (int j = 1; j <= n2; j++) {
            if (A[i] != B[j]) {
                temp[j] = max(temp[j - 1], DP[j]);
            } else {
                temp[j] = DP[j - 1] + 1;
            }
        }
        for (int k = 0; k <= n2; k++) {
            DP[k] = temp[k];
        }
        free(temp);
    }

    printf("%d\n", DP[n2]);

    free(A);
    free(B);
    free(DP);

    return 0;
}
