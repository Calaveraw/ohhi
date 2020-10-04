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
struct node *current; /* stored node upon traversal */
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

/* Define header before calling operation */
struct node *min(struct node *r);

/* Delete a node with data at or after r */
struct node *delete_node(struct node *r, char data)
{
    struct node *tmp;
    
    if (!r)
        return NULL;
    else if (data < r->data)
        r->left = delete_node(r->left, data);
    else if (data > r->data)
        r->right = delete_node(r->right, data);
    else { /* data = r->data */
        if (r->left && r->right) {/* two children */
            tmp = min(r->right);
            r->data = tmp->data;
            r->right = delete_node(r->right, (char)(tmp->data));
        }
        else {/* one child or zero children (leaf) */
            tmp = r;
            if (r->left == NULL)
                r = r->right;
            else if (r->right == NULL)
                r = r->left;
            free(tmp); /* destroy the node */
        }
    }
    
    return r;
}


/* Search for a node with key value data in r */
struct node *search(struct node *r, char data)
{
    if (r == NULL || r->data == data)
        return r;
    else if (data < r->data)
        return search(r->left, data);
    else /* data > r->data */
        return search(r->right, data);
}


/* Search for the node with minimum key value in r */
struct node *min(struct node *r)
{
    if (r == NULL || r->left == NULL)
        return r;
    else
        return min(r->left);
}


/* Search for the node with maximum key value in r */
struct node *max(struct node *r)
{
    if (r == NULL || r->right == NULL)
        return r;
    else
        return max(r->right);
}


struct node *pred(struct node *r, struct node *n)
{
    if (n->left != NULL)
        return max(n->left);
    
    if (!r || r->data == n->data)
        return NULL;
    else if (n->data > r->data) {
        current = r;
        pred(r->right, n);
    }
    else /* n->data < r->data) */
        pred(r->left, n);
    
    return current;
}


struct node *succ(struct node *r, struct node *n)
{
    //    struct node *current;
    
    if (n->right != NULL)
        return min(n->right);
    
    if (!r || r->data == n->data)
        return NULL;
    else if (n->data < r->data) {
        current = r;
        succ(r->left, n);
    }
    else /* n->data > r->data) */
        succ(r->right, n);
    
    return current;
}


/* Preorder traversal and output of tree with root r */
void print_tree_preorder(struct node *r)
{
    if (r != NULL) {
        printf("%c\n", r->data);
        print_tree_preorder(r->left);
        print_tree_preorder(r->right);
    }
}


/* Inorder traversal and output of tree with root r */
void print_tree_inorder(struct node *r)
{
    if (r != NULL) {
        print_tree_inorder(r->left);
        printf("%c\n", r->data);
        print_tree_inorder(r->right);
    }
}


/* Postorder traversal and output of tree with root r */
void print_tree_postorder(struct node *r)
{
    if (r != NULL) {
        print_tree_postorder(r->left);
        print_tree_postorder(r->right);
        printf("%c\n", r->data);
    }
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
    
    printf("%s\n\n", input); /* check input */
    
    int i;
    for (i=0; input[i] != '\0'; i++) {
        root = insert_node(root, input[i]);
    }
    
    print_tree_inorder(root); /* sequential console ouput*/
    printf("\n\n");
    print_tree_diagram(root,0); /* left to right console output*/
    printf("\n\n");
    //    printf("%c\n", succ(root,search(root,'L'))->data);
    //    printf("\n\n");
    //    printf("%c\n", pred(root,search(root,'S'))->data);
    //    printf("\n\n");
    
    print_tree_diagram(delete_node(root,'M'),0); /* left to right console output*/
    printf("\n\n");
    
    return 0; /* return EXIT_SUCCESS */
}
