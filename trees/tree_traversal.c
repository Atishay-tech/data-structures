#include <stdio.h>
#include "bst.c"

void in_order(Nodeptr root);
void pre_order(Nodeptr root);
void post_order(Nodeptr root);

/*
int main()
{
    void test(void);
    test();

    return 0;
}
*/

/* in_order: in-order traversal of the BST */
void in_order(Nodeptr root)
{
    if (root) {
        in_order(root->left);
        printf("Key:%2d   Count:%2d\n", root->key, root->count);
        in_order(root->right);
    }
}

/* pre_order: pre-order traversal of the BST */
void pre_order(Nodeptr root)
{
    if (root) {
        printf("Key:%2d   Count:%2d\n", root->key, root->count);
        pre_order(root->left);
        pre_order(root->right);
    }
}

/* post_order: post-order traversal of the tree */
void post_order(Nodeptr root)
{
    if (root) {
        post_order(root->left);
        post_order(root->right);
        printf("Key:%2d   Count:%2d\n", root->key, root->count);
    }
}


/* test: testing function I used to test the above functions
void test(void)
{
    Nodeptr root = NULL;

    insert_node(&root, 3);
    insert_node(&root, 2);
    insert_node(&root, 1);
    insert_node(&root, 4);
    insert_node(&root, 5);
    insert_node(&root, 6);
    insert_node(&root, 0);
    
    printf("In-Order Traversal\n");
    in_order(root);
    printf("Pre-order Traversal\n");
    pre_order(root);
    printf("Post-order Traversal\n");
    post_order(root);
}
*/