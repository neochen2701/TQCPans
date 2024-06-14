n1, n2 = map(int, input().split())
A = [0]
A.extend(map(int, input().split()))
B = [0]
B.extend(map(int, input().split()))

DP = [0 for i in range(n2+1)]
for i in range(1, n1+1):
    temp = [0 for i in range(n2+1)]
    for j in range(1, n2+1):
        if A[i] != B[j]: temp[j] = max([temp[j-1], DP[j]])
        else: temp[j] = DP[j-1]+1
    DP = temp;

print(DP[n2])
