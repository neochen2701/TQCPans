size = 12
sum_of_even_index = 0
count = 0
aList = []

for i in range(size):
    aList.append(eval(input()))

for i in range(size):
    count += 1
    print('%3d' % aList[i], end = '\n' if count % 3 == 0 else '')
    if i % 2 == 0:
        sum_of_even_index += aList[i]

print(sum_of_even_index)