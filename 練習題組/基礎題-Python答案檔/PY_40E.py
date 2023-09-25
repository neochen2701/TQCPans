min_value = 9999
max_value = 0

for i in range(6):
    val = int(input())
    if val > max_value:
        max_value = val
    if val < min_value:
        min_value = val
    
print(max_value - min_value)