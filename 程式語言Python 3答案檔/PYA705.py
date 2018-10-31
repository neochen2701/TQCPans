set1 = set()
set2 = set()
set3 = set()

print("Input to set1:")
for i in range(5):
    num = int(input())
    set1.add(num)

print("Input to set2:")
for i in range(3):
    num = int(input())
    set2.add(num)

print("Input to set3:")
for i in range(9):
    num = int(input())
    set3.add(num)

print("set2 is subset of set1:", set2.issubset(set1))
print("set3 is superset of set1:", set3.issuperset(set1))
