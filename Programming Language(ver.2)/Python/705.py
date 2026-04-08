n = {}
for i in range(3):
    a,b = input().split()
    n[a] = b
tot = 0
for i in range(5):
    c = input()
    if c in n:
        tot += int(n[c])
print(tot)