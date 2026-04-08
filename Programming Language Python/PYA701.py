num = []

while True:
    n = int(input())
    if n == -9999:
        break
    num.append(n)

num_tuple = tuple(num)
print(num_tuple)
print("Length:", len(num_tuple))
print("Max:", max(num_tuple))
print("Min:", min(num_tuple))
print("Sum:", sum(num_tuple))
