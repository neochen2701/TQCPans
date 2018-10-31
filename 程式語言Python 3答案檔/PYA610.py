num_week = 4
num_day = 3
temp = []

for i in range(num_week):
    temp.append([])
    print("Week %d:" % (i+1))
    for j in range(num_day):
        temp[i].append(eval(input("Day %d:" % (j+1))))

comb = []
for i in range(num_week):
    comb.extend(temp[i])

avg = sum(comb) / (num_week*num_day)
print("Average: %.2f" % avg)
print("Highest:", max(comb))
print("Lowest:", min(comb))