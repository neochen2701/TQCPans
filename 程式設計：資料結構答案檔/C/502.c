#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_SIZE 100000
#define BUFFER_SIZE 1000000

int arr[MAX_SIZE];
int n = 0;

typedef struct {
    int max_sum;
    int start;
    int end;
} subarray_result;

subarray_result max_crossing_sum(int low, int mid, int high) {
    int left_sum = INT_MIN, right_sum = INT_MIN;
    int sum = 0;
    int max_left = mid, max_right = mid;
    
    for (int i = mid; i >= low; i--) {
        sum += arr[i];
        if (sum > left_sum) {
            left_sum = sum;
            max_left = i;
        }
    }
    
    sum = 0;
    for (int i = mid + 1; i <= high; i++) {
        sum += arr[i];
        if (sum > right_sum) {
            right_sum = sum;
            max_right = i;
        }
    }
    
    subarray_result result;
    result.max_sum = left_sum + right_sum;
    result.start = max_left;
    result.end = max_right;
    return result;
}

subarray_result max_subarray_sum(int low, int high) {
    if (low == high) {
        return (subarray_result){arr[low], low, high};
    }
    
    int mid = (low + high) / 2;
    subarray_result left = max_subarray_sum(low, mid);
    subarray_result right = max_subarray_sum(mid + 1, high);
    subarray_result crossing = max_crossing_sum(low, mid, high);
    
    if (left.max_sum >= right.max_sum && left.max_sum >= crossing.max_sum) {
        return left;
    } else if (right.max_sum >= left.max_sum && right.max_sum >= crossing.max_sum) {
        return right;
    } else {
        return crossing;
    }
}

int main() {
    char buffer[BUFFER_SIZE];
    if (fgets(buffer, BUFFER_SIZE, stdin) != NULL) {
        char* token = strtok(buffer, " ");
        while (token != NULL) {
            arr[n++] = atoi(token);
            token = strtok(NULL, " ");
        }
    }

    if (n == 0) {
        printf("0\n0\n0\n");
        return 0;
    }

    subarray_result result = max_subarray_sum(0, n - 1);
    printf("%d\n%d\n%d\n", result.max_sum, result.start, result.end);

    return 0;
}
