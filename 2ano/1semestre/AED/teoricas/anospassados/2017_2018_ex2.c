#include <stdio.h>

typedef struct tree_node
{
    struct tree_node *left; // pointer to the left branch (a sub-tree)
    struct tree_node *right; // pointer to the right branch (a sub-tree)
    struct tree_node *parent; // pointer to the parent node (NULL for the root node)
    int data; // the data (only one node can have a given data value)
}
tree_node;

int CountNumLessOrEqualNode(tree_node *node, int v) {
    if (node == NULL) {
        return 0;
    }
    int left_count = CountNumNodes(node->left, v);
    int right_count = CountNumNodes(node->right, v);

    if (node->data <= v) {
        return 1 + left_count + right_count;
    } else {
        return left_count + right_count;
    }
}