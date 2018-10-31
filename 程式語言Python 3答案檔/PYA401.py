total = 10

min_num = eval(input())
for i in range(total-1):
    num = eval(input())
    if num < min_num:
        min_num = num
    
print(min_num)
