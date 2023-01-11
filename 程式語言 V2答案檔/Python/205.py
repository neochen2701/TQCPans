compute_list = [0]*7
for i in range(10):
    n = int(input())
    if n >= 1 and n <= 6:
        compute_list[n] += 1
    else:
        compute_list[0] += 1

for i in range(1, 7):
    print('number' + str(i) + ':' + str(compute_list[i]))
print('error:' + str(compute_list[0]))