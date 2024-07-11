#include "BST.h"
#include <stdlib.h>
#include <stdio.h>

BST *get_bst(){
    BST *bst = (BST *)malloc(sizeof(BST));
    if(bst == NULL){
        printf("%s\n", "Could not allocate memory for binary search tree");
        return NULL;
    }
    bst->root = NULL;
    bst->size = 0;
    return bst;
}

void preorder_bst(BST *bst){
    printf("%s", "[");
    preorder_aux_bst(bst->root);
    printf("%s\n", "]");
}

void preorder_aux_bst(BSTNode *root){
    if(root == NULL)
        return;
    printf("%i%s", root->element, " ");
    preorder_aux_bst(root->left);
    preorder_aux_bst(root->right);
}

void inorder_bst(BST *bst){
    printf("%s", "[");
    inorder_aux_bst(bst->root);
    printf("%s\n", "]");
}

void inorder_aux_bst(BSTNode *root){
    if(root == NULL)
        return;
    inorder_aux_bst(root->left);
    printf("%i%s", root->element, " ");
    inorder_aux_bst(root->right);
}

void postorder_bst(BST *bst){
    printf("%s", "[");
    postorder_aux(bst->root);
    printf("%s\n", "]");
}

void postorder_aux(BSTNode *root){
    if(root == NULL)
        return;
    postorder_aux(root->left);
    postorder_aux(root->right);
    printf("%i%s", root->element, " ");
}

int height_bst(BST *bst){
    return height_aux(bst->root);
}

int height_aux(BSTNode *root){
    if(root == NULL)
        return 0;
    int left_height = height_aux(root->left);
    int right_height = height_aux(root->right);
    if(left_height > right_height){
        return 1+left_height;
    }else{
        return 1+right_height;
    }
}

int is_leaf(BSTNode *root){
    return root->left == NULL && root->right == NULL;
}

int node_children_count(BSTNode *root){
    return (root->left == NULL ? 0 : 1) + (root->right == NULL ? 0
                                                            : 1);
}

BSTNode *get_unique_child(BSTNode *root){
    return root->left == NULL ? root->right : root->left;
}

void insert_bst(BST *bst, int element){
    bst->root = insert_bst_aux(bst->root, element);
    bst->size++;
}

BSTNode * insert_bst_aux(BSTNode *root, int element){
    if(root == NULL){
        root = (BSTNode *)malloc(sizeof(BSTNode));
        root->left = root->right = NULL;
        root->element = element;
        return root;
    }
    if(element < root->element){
        root->left = insert_bst_aux(root->left, element);
        return root;
    }else{
        root->right = insert_bst_aux(root->right, element);
        return root;
    }

}


int contains_bst(BST *bst, int element){
    return contains_aux_bst(bst->root, element);
}
int contains_aux_bst(BSTNode *root, int element){
    if(root == NULL){
        return 0;
    }
    if(root->element == element){
        return 1;
    }else if(element  > root->element){
        return contains_aux_bst(root->right, element);
    }else{
        return contains_aux_bst(root->left, element);
    }
}
int find_bst(BST *bst, int element){
    return find_aux_bst(bst->root, element);
}

int find_aux_bst(BSTNode *root, int element){
    if(root == NULL){
        printf("%s\n", "Could not find element");
        exit(EXIT_FAILURE);
    }
    if(root->element == element){
        return root->element;
    }else if(element > root->element){
        return find_aux_bst(root->right, element);
    }else{
        return find_aux_bst(root->left, element);
    }
}

int get_size_bst(BST *bst){
    return bst->size;
}

void clear_bst(BST *bst){
    clear_aux_bst(bst->root);
    bst->root = NULL;
    bst->size = 0;
}

void clear_aux_bst(BSTNode *root){
    if(root == NULL)
        return;
    clear_aux_bst(root->left);
    clear_aux_bst(root->right);
    free(root);
}

void free_bst(BST *bst){
    clear_bst(bst);
    free(bst->root);
    free(bst);
}


int internal_count_bst(BST *bst){
    return internal_count_aux_bst(bst->root);
}
int internal_count_aux_bst(BSTNode *root){
    if(root == NULL)
        return 0;
    if(is_leaf(root))
        return 0;
    return 1 + internal_count_aux_bst(root->left) + internal_count_aux_bst(root->right);
}

int leaf_count_bst(BST *bst){
    return leaf_count_aux_bst(bst->root);
}

int leaf_count_aux_bst(BSTNode *root){
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
        return 1;
    return 0 + leaf_count_aux_bst(root->left) + leaf_count_aux_bst(root->right);
}


int node_count_bst(BST *bst){
    return node_count_aux_bst(bst->root);
}

int node_count_aux_bst(BSTNode *root){
    if(root == NULL)
        return 0;
    return 1 + node_count_aux_bst(root->left) + node_count_aux_bst(root->right);
}

int remove_bst(BST *bst, int element){
    int result;
    bst->root = remove_aux_bst(bst->root, element, &result);
    bst->size--;
}
BSTNode * remove_aux_bst(BSTNode *root, int element, int *result){
    if(root == NULL){
        printf("%s\n", "No element matches the specified one");
        exit(EXIT_FAILURE);
    }
    if(element < root->element){
        root->left = remove_aux_bst(root->left, element, result);
        return root;
    }else if(element > root>element){
        root->right = remove_aux_bst(root->right, element, result);
        return root;
    }else{
        *result = root->element;
        if(is_leaf(root)){
            free(root);
            return NULL;
        }
        if(node_children_count(root) == 1){
            BSTNode *child = get_unique_child(root);
            free(root);
            return child;
        }else{
            BSTNode *succ = succesor(root->right);
            int temp = root->element;
            root->element = succ->element;
            succ->element = temp;
            root->right = remove_aux_bst(root->right, element, result);
            return root;
        }
    }
}

BSTNode *succesor(BSTNode *root){
    if(root->left == NULL){
        return root;
    }else{
        return succesor(root->left);
    }
}