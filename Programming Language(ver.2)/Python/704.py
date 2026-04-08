n = input()
input_list = input().split(' ')
for i in range(len(input_list)):
    if input_list.count(input_list[i]) > len(input_list) / 2:
        print(input_list[i])
        exit()
print('error')