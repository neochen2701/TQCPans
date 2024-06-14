def generate_combinations(items):  
    combinations = []
    for i in range(len(items)):
        for j in range(i + 1, len(items)):
            combinations.append(sorted([items[i],  items[j]]))
    return combinations

def compute(order, relations, combinations):
    for i in range(len(relations)):
        if  combinations[i][0] in order and combinations[i][1] in order:
            relations[i] += 1

def sortRelation(relations, combinations):
    for i in range(len(relations)-1):
        for j in range(len(relations)-i-1):
            if relations[j]<relations[j+1] or (relations[j]==relations[j+1] and combinations[j]<combinations[j+1]) : 
                relations[j], relations[j+1] = relations[j+1], relations[j]
                combinations[j], combinations[j+1] = combinations[j+1], combinations[j]
    for i in range(3):
        for c in combinations[i]:
            print(c, end=' ')       
        print(relations[i])       
     
def check():
    items =['apple', 'watermelon', 'pawpaw', 'banana', 'pineapple']
    combinations = generate_combinations(items)
    relations = [0 for i in range(len(combinations))]
    n = int(input())
    for i in range(n):
        order = input().split()
        compute(order, relations,combinations)
    
    sortRelation(relations, combinations)
    
if __name__ == "__main__":
    check()