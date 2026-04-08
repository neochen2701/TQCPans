input_list = []
for i in range(6):
    input_list.append(int(input()))
input_list.sort()
print(sum(input_list[3:]) - sum(input_list[:3]))
