with open(r'read.txt', 'r') as file:
    graph = []
    
    for line in file.readlines():
        lst = line.strip().split(',')
        lst = [eval(x) for x in lst]
        graph.append(lst)

degree = []
weight = []

for node in graph:
    deg = sum([1 if x>0 else 0 for x in node])
    degree.append(str(deg))
    weight.append(sum(node))

print(f"Degree:{','.join(degree)}")
print(max(weight) - min(weight))

