score = 0
input_list = []
for i in range(10):
    n = int(input())
    input_list = [x + n for x in input_list]
    input_list.append(n)

print('score = ' + str(sum(i > 3 for i in input_list)))



