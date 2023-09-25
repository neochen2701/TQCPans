type1 = 0
type2 = 0
type3 = 0

for i in range(6):
    val = int(input())
    if val == 1:
        type1 += 1
    if val == 2:
        type2 += 1
    if val == 3:
        type3 += 1

if type1 != 2 or type2 != 2 or type3 != 2:
    print("No")
else:
    print("Yes")