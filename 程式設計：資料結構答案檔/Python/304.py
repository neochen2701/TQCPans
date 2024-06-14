m = int(input())
set0 = {input() for i in range(m)}

count = 0
for s in set0:
    for i in range(1, len(s)//2+1):
        if s[:i] == s[-i:] and s[i:-i] in set0: count += 1
print(count)