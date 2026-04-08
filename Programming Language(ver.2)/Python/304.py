def compute(input_list):
    cnt = 0
    for x in input_list:
        if x % 3 == 0:
            cnt += 1
    return cnt

input_list = []
for i in range(6):
    number = int(input())
    input_list.append(number)
print(compute(input_list))