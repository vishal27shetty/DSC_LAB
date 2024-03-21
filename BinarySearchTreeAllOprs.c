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

int height(node* tree)
{
    if (tree == NULL)
        return 0;
    else
    {
        int lheight = height(tree->left);
        int rheight = height(tree->right);
 
        if (lheight > rheight)
            return(lheight+1);
        else return(rheight+1);
    }
}

int countNodes(node* tree)
{
    if (tree == NULL)
        return 0;
    return 1 + countNodes(tree->left) + countNodes(tree->right);
}

int countInternalNodes(node* tree)
{
    if (tree == NULL || (tree->left == NULL && tree->right == NULL))
        return 0;
    return 1 + countInternalNodes(tree->left) + countInternalNodes(tree->right);
}

int countLeafNodes(node* tree)
{
    if(tree == NULL)       
        return 0;
    if(tree->left == NULL && tree->right==NULL)      
        return 1;            
    else
        return countLeafNodes(tree->left) + countLeafNodes(tree->right);      
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
    int choice, val;
    
    while(1) {
        printf("\n1. Insert\n2. Delete\n3. Inorder traversal\n4. Preorder traversal\n5. Postorder traversal\n6. Height of tree\n7. Number of nodes\n8. Number of internal nodes\n9. Number of leaf nodes\n10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter value to be inserted: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;
            case 2:
                printf("Enter value to be deleted: ");
                scanf("%d", &val);
                root = deleteNode(root, val);
                break;
            case 3:
                printf("Inorder traversal: ");
                inorder_traversal(root);
                printf("\n");
                break;
            case 4:
                printf("Preorder traversal: ");
                preorder_traversal(root);
                printf("\n");
                break;
            case 5:
                printf("Postorder traversal: ");
                postorder_traversal(root);
                printf("\n");
                break;
            case 6:
                printf("Height of tree: %d\n", height(root));
                break;
            case 7:
                printf("Number of nodes: %d\n", countNodes(root));
                break;
            case 8:
                printf("Number of internal nodes: %d\n", countInternalNodes(root));
                break;
            case 9:
                printf("Number of leaf nodes: %d\n", countLeafNodes(root));
                break;
            case 10:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
