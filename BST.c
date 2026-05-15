#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int num;
    struct node *lchild; // Nodes smaller than root comes here.
    struct node *rchild; // Nodes greater than root comes here.
} node;

node* createNode(int num) {
    node *nnptr = malloc(sizeof(struct node));
    nnptr->num = num;
    nnptr->lchild = nnptr->rchild = NULL;
}

void traverse(struct node *root) {
    if(root == NULL) return;
    traverse(root->lchild);
    printf("%d\t", root->num);
    traverse(root->rchild);
}

int main() {
    int list[5] = {50, 110, 105, 60, 55};
    
    // Making a BST
    // 0. A structure with 1 Data Field and 2 Child Pointers.
    // 1. We will need a Root.
    // 2. A function to create and return node.
    // 3. A function that finds the parent for new node in tree.
    
    struct node *root = NULL;
    root = createNode(100);
    printf("root->num = %d\n", root->num);
    
    node *par = NULL, *child = root;
    node *nnptr;
    for(int i = 0; i < 5; i++) {
        child = root;
        printf("list[%d] = %d\n", i, list[i]);
        nnptr = createNode(list[i]);
        while(child != NULL) {
            par = child;
            if(nnptr->num < par->num) {
                printf("Nnptr is smaller than parent. Go to left.\n");
                child = child->lchild;
            }
            else {
                printf("Nnptr is greater than parent. Go to right.\n");
                child = child->rchild;
            }
        }
        // Adding new node to its correct place now that we have its respective parent!
        if(nnptr->num < par->num) {
            printf("Adding %d to left of %d!\n", nnptr->num, par->num);
            par->lchild = nnptr;
        }
        else {
            printf("Adding %d to left of %d!\n", nnptr->num, par->num);
            par->rchild = nnptr;
        }
        traverse(root);
    }

    return 0;
}
