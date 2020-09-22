/* This program demonstrates a binary tree */

#include <stdio.h>
#include <stdlib.h> /* declares malloc */

struct node
{
    char data; /* key */
    struct node *left;
    struct node *right;
};

struct node *root; /* root of the tree */

char input[] = { "ALGORITHMS2" };


/* Insert a node with data at or after r */
struct node *insert_node(struct node *r, char data)
{
    if (!r) { /* (r == NULL) */
        r = (struct node *) malloc(sizeof(struct node)); /* create the node */
        r->left = NULL;
        r->right = NULL;
        r->data = data;
    }
    
    if (data < r->data)
        r->left = insert_node(r->left, data);
    else if (data > r->data)
        r->right = insert_node(r->right, data);
    
    return r;
}


/* Tree diagram output (left to right) of tree with root r and level l */
void print_tree_diagram(struct node *r, int l)
{
    int i;
    
    if (!r)
        return;
    
    print_tree_diagram(r->right, l+1);
    for (i=0; i<l; ++i)
        printf("   ");
    printf("%c\n", r->data);
    print_tree_diagram(r->left, l+1);
}


/* Test */
int main()
{
    root = NULL; /* initialize the root */
    
    int i;
    for (i=0; input[i] != '\0'; i++) {
        root = insert_node(root, input[i]);	/* add characters of input string into tree */
    }

    print_tree_diagram(root,0); /* left to right console output*/
    
    return 0; /* return EXIT_SUCCESS */
}