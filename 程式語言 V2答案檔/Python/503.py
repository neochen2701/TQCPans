a, b = int(input()), int(input())
output_list = []
for i in range(1, int(a / 2) + 1):
    if i*i < a:
        # output_list.append(i ** b)
        print(i ** b)