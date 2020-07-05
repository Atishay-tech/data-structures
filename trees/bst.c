/* Binary Search Tree implemented using linked list */
#include <stdio.h>
#include <stdlib.h>

#define max(A, B) ((A) > (B) ? (A) : (B)) 

typedef struct tnode {
    int key;
    int count;
    struct tnode *left;
    struct tnode *right;
} Treenode;

typedef Treenode *Nodeptr;


static Nodeptr new_node(int key);
void insert_node(Nodeptr *root, int key);
void delete_tree(Nodeptr *root);
Nodeptr find_key(Nodeptr root, int key);
int height(Nodeptr root);
int size(Nodeptr root);
void print_tree(Nodeptr root);


/*
int main()
{
    void test(void);
    test();

    return 0;
}
*/

/* new_node: utility function that creates a new node
             and returns a pointer to it */
static Nodeptr new_node(int key)
{
    Nodeptr node = (Nodeptr)malloc(sizeof(Treenode));
    
    node->key = key;
    node->count = 1;
    node->left = node->right = NULL;

    return node;
}

/* insert_node: inserts a new node with value key into the tree */
void insert_node(Nodeptr *root, int key)
{
    Nodeptr new_node(int key);

    if (!(*root))
        *root = new_node(key);
    else if (key < (*root)->key)
        insert_node(&(*root)->left, key);
    else if (key > (*root)->key)
        insert_node(&(*root)->right, key);
    else if (key == (*root)->key)
        (*root)->count += 1;
}

/* find_key: returns the pointer to the node having the given key */
Nodeptr find_key(Nodeptr root, int key)
{
    if (root == NULL)
        return NULL;
    else if (key == root->key)
        return root;
    else if (key < root->key)
        return find_key(root->left, key);
    else if (key > root->key)
        return find_key(root->right, key);
}

/* delete_tree: frees the memory occupied by the binary tree */
void delete_tree(Nodeptr *root)
{
    void deltree(Nodeptr root);
    deltree(*root);
    *root = NULL;
}

/* deltree: utility function for the function delete_tree */
void deltree(Nodeptr root)
{
    if (root) {
        deltree(root->left);
        deltree(root->right);
        free(root);
    }
}

/* height: returns the height of the tree */
int height(Nodeptr root)
{
    if (root == NULL)
        return 0;
    else
        return 1 + max(height(root->left),
                       height(root->right));
}

/* size: returns the number of elements in the tree
         including duplicate elements */
int size(Nodeptr root)
{
    if (root == NULL)
        return 0;
    else
        return root->count
               + size(root->left)
               + size(root->right);
}

/* print_tree: in-order traversal of tree */
void print_tree(Nodeptr root)
{
    if (root) {
        print_tree(root->left);
        printf("Key:%2d   Count:%2d\n", root->key, root->count);
        print_tree(root->right);
    }
}

/* test: utility function I used to test the above functions 
void test(void)
{   
    Nodeptr root = NULL;

    printf("%p\n", root);
    insert_node(&root, 7);
    insert_node(&root, 7);
    insert_node(&root, 6);
    insert_node(&root, 1);
    insert_node(&root, 2);
    insert_node(&root, 9);
    insert_node(&root, 10);
    insert_node(&root, 2);
    printf("%d\n", root->key);
    printf("%p\n", find_key(root, 7));
    printf("%d\n", height(root));
    printf("%d\n", size(root));
    print_tree(root);
    delete_tree(&root);
    printf("%p\n", find_key(root, 7));
    printf("%p\n", root);
    printf("%d\n", height(root));
    printf("%d\n", size(root));
}
*/