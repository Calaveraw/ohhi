
struct node
{
    char data; /* key */
    struct node *left;
    struct node *right;
    int height; /* height information */
};


/* Get the height information of a node */
int get_height(struct node *n)
{
    if (!n)
        return -1;
    else
        return n->height;
}


/* Get the larger of two different height values */
int max_height(int h1, int h2)
{
    return h1 > h2 ? h1 : h2;
}


/* Rotate left subtree and root to the right */
/* Needs: left subtree*/
struct node *single_rotate_right(struct node *r)
{
    struct node *tmp; printf("single_rotate_right(%c)\n",r->data);

    /* actual rotation */
    tmp = r->left;
    r->left = tmp->right;
    tmp->right = r;

    /* height update */
    r->height = max_height(get_height(r->left), get_height(r->right));
    tmp->height = max_height(get_height(tmp->left), r->height) + 1;

    return tmp; /* new root */
}


/* Rotate right subtree and root to the left */
/* Needs: right subtree */
struct node *single_rotate_left(struct node *r)
{
    struct node *tmp; printf("single_rotate_left(%c)\n",r->data);

    /* actual rotation */
    tmp = r->right;
    r->right = tmp->left;
    tmp->left = r;

    /* height update */
    r->height = max_height(get_height(r->left), get_height(r->right));
    tmp->height = max_height(get_height(tmp->right), r->height) + 1;

    return tmp; /* new root */
}