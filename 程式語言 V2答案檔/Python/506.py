number = int(input())
factor_list = []
for i in range(2, int(number / 2) + 1):
    while number % i == 0:
        number /= i
        factor_list.append(i)

if len(factor_list) == 0:
    print('-1')
    exit()

factor_str = ''
for idx in range(len(factor_list)):
    factor_str += str(factor_list[idx])
    if idx != len(factor_list) - 1:
        factor_str += '*'
print(factor_str)