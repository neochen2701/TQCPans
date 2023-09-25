text = input()
target = input()
result = 0

for c in text:
    if c == target:
        result += 1

print(result)