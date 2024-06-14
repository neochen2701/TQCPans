class TreeNode:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

    def preorder_traversal(self):
        result = []
        result.append(self.value)

        if self.left:
            result.extend(self.left.preorder_traversal())

        if self.right:
            result.extend(self.right.preorder_traversal())

        return result

def insert_node(root, value):
    if root is None:
        return TreeNode(value)
    else:
        if value < root.value:
            root.left = insert_node(root.left, value)
        else:
            root.right = insert_node(root.right, value)
    return root

def level_order_traversal(root):
    result = []
    if root is None:
        return result

    queue = [root]

    while queue:
        current_node = queue.pop(0)
        result.append(current_node.value)

        if current_node.left:
            queue.append(current_node.left)
        if current_node.right:
            queue.append(current_node.right)

    return result

n = int(input())
values_list = list(map(int, input().split()))

root_node = None
for value in values_list:
    root_node = insert_node(root_node, value)

result_list = level_order_traversal(root_node)
print("Level-order:", end="")
print(" ".join([str(value) for value in result_list]))
print("Preorder:", end="")
preorder_result = root_node.preorder_traversal()
print(" ".join([str(value) for value in preorder_result]))
