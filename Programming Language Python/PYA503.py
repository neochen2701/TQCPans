def compute(a, b):
    return int((a+b)*(b-a+1)/2)

a = eval(input())
b = eval(input())

print(compute(a, b))