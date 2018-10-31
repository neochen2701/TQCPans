size = 10
sample = []
count = [0]*size

for i in range(size):
    num = int(input())

    sample.append(num)
    count[sample.index(num)] += 1

num_occu = max(count)

print(sample[count.index(num_occu)])
print(num_occu)