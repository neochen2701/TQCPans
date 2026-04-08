def compute(input_list):
    if input_list[1] == 1:
        return input_list[0] + input_list[2]
    elif input_list[1] == 2:
        return input_list[0] * input_list[2]

input_list = []
for i in range(3):
    x = int(input())
    input_list.append(x)
print(compute(input_list))
