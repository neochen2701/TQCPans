input_list = []
for i in range(9):
    input_list.append(int(input()))
input_list.sort()
sum = 0
for i in input_list:
    print(i)
    sum += int(i)
print('sum = '+ str(sum))