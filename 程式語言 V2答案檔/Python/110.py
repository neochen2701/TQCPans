
input_list = []
for i in range(3):
    input_list.append(int(input()))

if input_list[0] >= 60 and input_list[0] < 100:
    print('1')
else:
    print('0')

print(format((input_list[1]+1)/10, '.2f'))

if input_list[0] >= input_list[2]:
    print(input_list[0])
else:
    print(input_list[2])