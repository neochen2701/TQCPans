#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int value);
struct TreeNode* insertNode(struct TreeNode* root, int value);
void levelOrderTraversal(struct TreeNode* root, int isFirst);
void preorderTraversal(struct TreeNode* root, int isFirst);

struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode* insertNode(struct TreeNode* root, int value) {
    if (root == NULL) {
        return createNode(value);
    } else {
        if (value < root->value) {
            root->left = insertNode(root->left, value);
        } else {
            root->right = insertNode(root->right, value);
        }
    }
    return root;
}

void preorderTraversal(struct TreeNode* root, int isFirst) {
    if (root == NULL) {
        return;
    }
    if (!isFirst) {
        printf(" ");
    }
    printf("%d", root->value);
    preorderTraversal(root->left, 0);
    preorderTraversal(root->right, 0);
}

void levelOrderTraversal(struct TreeNode* root, int isFirst) {
    if (root == NULL) {
        return;
    }
    struct TreeNode** queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        struct TreeNode* currentNode = queue[front++];
        if (!isFirst) {
            printf(" ");
        }
        printf("%d", currentNode->value);
        isFirst = 0;

        if (currentNode->left != NULL) {
            queue = (struct TreeNode**)realloc(queue, (rear + 1) * sizeof(struct TreeNode*));
            queue[rear++] = currentNode->left;
        }

        if (currentNode->right != NULL) {
            queue = (struct TreeNode**)realloc(queue, (rear + 1) * sizeof(struct TreeNode*));
            queue[rear++] = currentNode->right;
        }
    }
    free(queue);
}

int main() {
    int n, i;
    struct TreeNode* root = NULL;
    scanf("%d", &n);
    int arr[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < n; i++) {
        root = insertNode(root, arr[i]);
    }
    printf("Level-order:");
    levelOrderTraversal(root, 1);
    
    printf("\nPreorder:");
    preorderTraversal(root, 1);

    return 0;
}
