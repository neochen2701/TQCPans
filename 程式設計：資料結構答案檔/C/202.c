#include <stdio.h>
#include <string.h>

char tree[20];

void get_nodes_from_input(char inp[]) {
    int count = 1;
    tree[0] = ' ';

    for (int i = 0; inp[i] != '\0'; i++)
        if (inp[i] != ',') {
            tree[count] = inp[i];
            count++;
        } else if (inp[i + 1] == ',') {
            tree[count] = ' ';
            count++;
        }
    tree[count] = '\0';
}

void inorder_tree(int idx) {
    if (idx < strlen(tree) && tree[idx] != ' ') {
        inorder_tree(2 * idx);
        printf("%c", tree[idx]);
        inorder_tree(2 * idx + 1);
    }
}

char* sort_array(char array[]) {
    int count = strlen(array);

    for (int i = 0; i < count - 1; i++)
        for (int j = i + 1; j < count; j++) {
            if (array[i] > array[j]) {
                char tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }

    return array;
}

void leaf_nodes() {
    char leaves[20];
    int count = 0;

    for (int i = 1; tree[i] != '\0'; i++) {
        if (tree[i] == ' ')
            continue;
        if (2 * i >= strlen(tree) || tree[2 * i] == ' ')
            if (2 * i + 1 >= strlen(tree) || tree[2 * i + 1] == ' ') {
                leaves[count] = tree[i];
                count++;
            }
    }
    leaves[count] = '\0';

    printf("%s", sort_array(leaves));
}

int main() {
    char input[40];

    scanf("%s", input);
    get_nodes_from_input(input);

    inorder_tree(1);

    printf("\n");
    leaf_nodes();

    return 0;
}
