s = input()
slist = [int(x) for x in s.split(' ')]

print("Total =", sum(slist))
print("Average =", sum(slist)/len(slist))