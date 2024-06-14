def inorder_tree(idx):
    if (idx < len(lst)) and lst[idx] != '':
        inorder_tree(2*idx)
        print(lst[idx], end='')
        inorder_tree(2*idx + 1)

def leaf_node():
    leaves = []
    
    for i in range(1, len(lst)):
        if (2*i >= len(lst)) or (lst[2*i] == ''):
            if (2*i+1 >= len(lst)) or (lst[2*i+1] == ''):
                leaves.append(lst[i])
    
    leaves.sort()
    print("".join(leaves))

inp = input()
lst = [None] + inp.split(',')

inorder_tree(1)

print("\n", end='')
leaf_node()
