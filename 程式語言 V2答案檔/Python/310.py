def compute(n):
    A_list = []
    for i in range(1, n):
        s = str(i)
        k = len(s)
        cnt = 0
        for j in range(k):
            cnt += int(s[j]) ** k
        if cnt == i:
            A_list.append(i)
    return A_list

n = int(input())
A_list = compute(n)
sum = 0
for x in A_list:
    print(x)
    sum += x
print(sum)