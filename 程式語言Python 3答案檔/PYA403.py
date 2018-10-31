a = int(input())
b = int(input())
count = total_sum = 0
time = 10

for i in range(a, b + 1):
    if i % 4 == 0 or i % 9 == 0:
        print('%-4d' % i, end='')
        total_sum += i
        count += 1

        if count % time == 0:
            print()

if count > 0 and count % 10 != 0:
    print()

print('%d' % count)
print(total_sum)
