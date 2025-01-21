#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node
{
    struct tree_node *left; // pointer to the left branch (a sub-tree)
    struct tree_node *right; // pointer to the right branch (a sub-tree)
    struct tree_node *parent; // pointer to the parent node (NULL for the root node)
    int data; // the data (only one node can have a given data value)
}
tree_node;

int CountNumNodes(tree_node *node, int v) {
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

tree_node *createNode(int value) {
    tree_node *newNode = (tree_node*)malloc(sizeof(tree_node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Função para inserir um valor na árvore
tree_node *insert(tree_node *root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value <= root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

void printTree(tree_node *root) {
    if (root != NULL) {
        // Recursively print the left subtree
        printTree(root->left);

        // Print the current node's data
        printf("%d ", root->data);

        // Recursively print the right subtree
        printTree(root->right);
    }
}


// Função principal (main) para teste
int main() {
    // Construir uma árvore de exemplo
    tree_node *root = NULL;
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 8);
    insert(root, 2);
    insert(root, 4);
    insert(root, 7);
    insert(root, 9);

    // Valor para comparar
    int v = 6;

    // Chamar a função e imprimir o resultado
    printTree(root);
    int result = CountNumNodes(root, v);
    printf("Numero de nos menores ou iguais a %d na arvore: %d\n", v, result);

    // Liberar a memória da árvore (pode ser feito de forma recursiva)
    free(root);

    return 0;
}