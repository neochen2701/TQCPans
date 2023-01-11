input_list = []
for i in range(6):
    input_list.append(input())

for i in range(6):
    if i == 2 or i == 5:
        print('%10s' % str(input_list[i]))
    else:
        print('%10s' % str(input_list[i]), end = ' ')

for i in range(6):
    if i == 2 or i == 5:
        print('{0: <10}'.format(input_list[i]))
    else:
        print('{0: <10}'.format(input_list[i]), end = ' ')