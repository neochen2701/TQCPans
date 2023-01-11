input_str = input()
U, L = '', ''
for i in input_str:
    if i.isupper():
        U += i
    else:
        L += i
print(U)
print(L)
print(len(U))