a = int(input())
b = int(input())
ans = 0
for i in range(a, b+1):
    if i % 2 == 1:
        ans += i

print(ans)