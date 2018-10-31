lst=[]

for i in range(10):
    lst.append(eval(input()))

total = sum(lst) - max(lst) - min(lst)
print(total) 
print("%.2f" % (total/8))