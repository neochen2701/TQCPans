lst = []

for i in range(10):
    lst.append(eval(input()))

lst.sort()
print(lst[-1], lst[-2], lst[-3])