#ifndef B_S_T_H
#define B_S_T_H

typedef struct BSTNode
{
    struct BSTNode *left, *right;
    int element;
} BSTNode;

typedef struct BST
{
    BSTNode *root;
    int size;
}BST;

BST *get_bst();
void insert_bst(BST *bst, int element);
int remove_bst(BST *bst, int element);
BSTNode *succesor(BSTNode *root);
BSTNode * remove_aux_bst(BSTNode *root, int element, int *result);
BSTNode * insert_bst_aux(BSTNode *root, int element);
void preorder_bst(BST *bst);
void preorder_aux_bst(BSTNode *root);
void inorder_bst(BST *bst);
void inorder_aux_bst(BSTNode *root);
void postorder_bst(BST *bst);
void postorder_aux(BSTNode *root);
int height_bst(BST *bst);
int height_aux(BSTNode *root);
int is_leaf(BSTNode *root);
int node_children_count(BSTNode *root);
BSTNode *get_unique_child(BSTNode *root);
int contains_bst(BST *bst, int element);
int contains_aux_bst(BSTNode *root, int element);
int find_bst(BST *bst, int element);
int find_aux_bst(BSTNode *root, int element);
int get_size_bst(BST *bst);
void clear_bst(BST *bst);
void clear_aux_bst(BSTNode *root);
void free_bst(BST *bst);
int internal_count_bst(BST *bst);
int internal_count_aux_bst(BSTNode *root);
int leaf_count_bst(BST *bst);
int leaf_count_aux_bst(BSTNode *root);
int node_count_bst(BST *bst);
int node_count_aux_bst(BSTNode *root);

#endif