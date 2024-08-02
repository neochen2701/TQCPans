def prefix_common_array(A, B, n):
    common_array = [0] * n

    for i in range(n):
        common_set = set(A[:i+1]) & set(B[:i+1])
        common_array[i] = len(common_set)

    print(' '.join(map(str, common_array)))


if __name__ == '__main__':
    N = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    prefix_common_array(A, B, N)
