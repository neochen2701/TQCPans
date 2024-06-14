package main

import (
	"fmt"
)

type TreeNode struct {
	value int
	left  *TreeNode
	right *TreeNode
}

func createNode(value int) *TreeNode {
	return &TreeNode{value: value}
}

func (root *TreeNode) insertNode(value int) *TreeNode {
	if root == nil {
		return createNode(value)
	}
	if value < root.value {
		root.left = root.left.insertNode(value)
	} else {
		root.right = root.right.insertNode(value)
	}
	return root
}

func preorderTraversal(root *TreeNode, isFirst *bool) {
	if root == nil {
		return
	}
	if !*isFirst {
		fmt.Print(" ")
	}
	fmt.Print(root.value)
	*isFirst = false
	preorderTraversal(root.left, isFirst)
	preorderTraversal(root.right, isFirst)
}

func levelOrderTraversal(root *TreeNode) {
	if root == nil {
		return
	}
	queue := []*TreeNode{root}
	isFirst := true
	for len(queue) > 0 {
		node := queue[0]
		queue = queue[1:]

		if !isFirst {
			fmt.Print(" ")
		}
		fmt.Print(node.value)
		isFirst = false

		if node.left != nil {
			queue = append(queue, node.left)
		}
		if node.right != nil {
			queue = append(queue, node.right)
		}
	}
}

func main() {
	var n, value int
	fmt.Scan(&n)

	var root *TreeNode
	for i := 0; i < n; i++ {
		fmt.Scan(&value)
		if root == nil {
			root = createNode(value)
		} else {
			root.insertNode(value)
		}
	}

	fmt.Print("Level-order:")
	levelOrderTraversal(root)

	fmt.Print("\nPreorder:")
	isFirst := true
	preorderTraversal(root, &isFirst)
}
