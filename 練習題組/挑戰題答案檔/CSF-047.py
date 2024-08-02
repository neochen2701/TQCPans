def calculate_B_sum(n, A):
    B = [0] * (n - 1)
    for i in range(1, n):
        count = sum(1 for k in range(i) if A[k] <= A[i])
        B[i - 1] = count
    return sum(B)

def main():
    result_list = []
    T = int(input())
    for _ in range(T):
        n = int(input())
        A = list(map(int, input().split()))
        result = calculate_B_sum(n, A)
        result_list.append(result)

    for item in result_list:
        print(item)

if __name__ == "__main__":
    main()