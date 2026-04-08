n = input()

if n != '0' and n != '1':
    print('error')
else:
    for i in range(1, 6):
        for j in range(1, 6):
            if n == '0':
                f = str(i) + ' x ' + str(j) + ' = ' + str(i * j)
            elif n == '1':
                f = str(j) + ' x ' + str(i) + ' = ' + str(i * j)
            if j == 5:
                print('%s\t'%f)
            else:
                print('%s\t'%f, end = '')