using System;
using System.Collections.Generic;

class TreeNode {
    public int Value { get; set; }
    public TreeNode Left { get; set; }
    public TreeNode Right { get; set; }

    public TreeNode(int value) {
        Value = value;
        Left = null;
        Right = null;
    }
}

class BinaryTree {
    public TreeNode Root { get; set; }

    public void InsertNode(int value) {
        Root = InsertNode(Root, value);
    }

    private TreeNode InsertNode(TreeNode root, int value) {
        if (root == null) {
            root = new TreeNode(value);
        } else {
            if (value < root.Value) {
                root.Left = InsertNode(root.Left, value);
            } else {
                root.Right = InsertNode(root.Right, value);
            }
        }
        return root;
    }

    public void LevelOrderTraversal() {
        if (Root == null) return;
        Queue<TreeNode> queue = new Queue<TreeNode>();
        queue.Enqueue(Root);

        bool isFirst = true;

        while (queue.Count > 0) {
            TreeNode currentNode = queue.Dequeue();
            if (!isFirst) Console.Write(" ");
            Console.Write(currentNode.Value);
            isFirst = false;

            if (currentNode.Left != null) queue.Enqueue(currentNode.Left);
            if (currentNode.Right != null) queue.Enqueue(currentNode.Right);
        }
    }

    public void PreorderTraversal() {
        PreorderTraversal(Root, true);
    }

    private void PreorderTraversal(TreeNode root, bool isFirst) {
        if (root == null) return;
        if (!isFirst) Console.Write(" ");
        Console.Write(root.Value);
        PreorderTraversal(root.Left, false);
        PreorderTraversal(root.Right, false);
    }
}

class Program {
    static void Main() {
        int n = int.Parse(Console.ReadLine());
        string[] numbers = Console.ReadLine().Split(' ');
        BinaryTree tree = new BinaryTree();

        foreach (string number in numbers) {
            tree.InsertNode(int.Parse(number));
        }

        Console.Write("Level-order:");
        tree.LevelOrderTraversal();

        Console.Write("\nPreorder:");
        tree.PreorderTraversal();
    }
}
