#include <stdio.h>

struct TreeNode {
    struct TreeNode* left;
    struct TreeNode* right;
    int item;
};

unsigned int CountNonLeafNodes(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left != NULL || root->right != NULL) {
        return 1 + CountNonLeafNodes(root->left) + CountNonLeafNodes(root->right);
    }
    return 0;
}

// 3.b
// Depth First Search

// 3.c

unsigned int CountValuesInRange(struct TreeNode* root, int a, int b) {
    if (root == NULL) {
        return 0;
    }
    if (a <= root->item && root->item <= b) {   // quer dizer que temos valores candidatos na esquerda e na direita da arvore
        return 1 + CountValuesInRange(root->left,a,b) + CountValuesInRange(root->right,a,b);
    } else {
        if (b < root->item) {   // só temos valores candidatos à esquerda
            return CountValuesInRange(root->left,a,b);
        } 
        else {   // só temos valores candidados à direita
            return CountValuesInRange(root->right,a,b);
        }
    }
}