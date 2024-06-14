import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class TreeNode {
    int value;
    TreeNode left, right;

    TreeNode(int value) {
        this.value = value;
        this.left = null;
        this.right = null;
    }
}

public class JPA203 {
    public static TreeNode createNode(int value) {
        return new TreeNode(value);
    }

    public static TreeNode insertNode(TreeNode root, int value) {
        if (root == null) {
            return createNode(value);
        } else {
            if (value < root.value) {
                root.left = insertNode(root.left, value);
            } else {
                root.right = insertNode(root.right, value);
            }
        }
        return root;
    }

    public static void preorderTraversal(TreeNode root, boolean isFirst) {
        if (root == null) {
            return;
        }
        if (!isFirst) {
            System.out.print(" ");
        }
        System.out.print(root.value);
        preorderTraversal(root.left, false);
        preorderTraversal(root.right, false);
    }

    public static void levelOrderTraversal(TreeNode root, boolean isFirst) {
        if (root == null) {
            return;
        }
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);

        while (!queue.isEmpty()) {
            TreeNode currentNode = queue.poll();
            if (!isFirst) {
                System.out.print(" ");
            }
            System.out.print(currentNode.value);
            isFirst = false;

            if (currentNode.left != null) {
                queue.add(currentNode.left);
            }

            if (currentNode.right != null) {
                queue.add(currentNode.right);
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        TreeNode root = null;

        for (int i = 0; i < n; i++) {
            int value = scanner.nextInt();
            root = insertNode(root, value);
        }

        System.out.print("Level-order:");
        levelOrderTraversal(root, true);

        System.out.print("\nPreorder:");
        preorderTraversal(root, true);
    }
}
