#include <stdlib.h>
#include <stdio.h>

struct node {
    int data;
    struct node * left;
    struct node * right;
};

typedef struct node node;

node *insert (node* tree, int val)
{
    if(tree == NULL)
    {
        node *newnode = (node*)malloc(sizeof(node));
        newnode->right=NULL;
        newnode->left=NULL;
        newnode->data=val;
        return newnode;
    }
    
    else if( val < tree->data)
        tree->left = insert(tree->left,val);
    else if( val > tree->data)
        tree->right = insert(tree->right,val);
    return tree;
}

void inorder_traversal(node * tree) {
    if (tree != NULL)
    {
        inorder_traversal(tree->left);
        printf("%d ",tree->data);
        inorder_traversal(tree->right);
    }
}

void postorder_traversal(node * tree) {
    if (tree != NULL)
    {
        postorder_traversal(tree->left);
        postorder_traversal(tree->right);
        printf("%d ",tree->data);
    }
}

void preorder_traversal(node * tree) {
    if (tree != NULL)
    {
        printf("%d ",tree->data);
        preorder_traversal(tree->left);
        preorder_traversal(tree->right);
    }
}

int main() {
    
    node *root = NULL;
    root = insert(root,10);
    root = insert(root,20);
    root = insert(root,32);
    root = insert(root,16);
    root = insert(root,9);

    printf("Inorder traversal: ");
    inorder_traversal(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorder_traversal(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder_traversal(root);
    printf("\n");

    return 0;
}
