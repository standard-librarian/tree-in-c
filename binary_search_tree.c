#include <stdio.h>
#include <stdlib.h>

#include "binary_search_tree.h"

int main(){
    TreeNode *root = NULL;

    insert(&root, 5);
    insert(&root, 10);
    insert(&root, 9);
    insert(&root, 2);
    insert(&root, 3);

    print_tree(root);

    printf("%d (%d)\n", 5, find(root, 5));
    printf("%d (%d)\n", 3, find(root, 3));
    printf("%d (%d)\n", 7, find(root, 7));
    printf("%d (%d)\n", 10, find(root, 10));
    printf("%d (%d)\n", 19, find(root, 19));

    return 0;
}

bool insert(TreeNode **root_ptr, int value){

    if((*root_ptr) == NULL){
        (*root_ptr) = creat_node(value);
        return true;
    }
    if(value == (*root_ptr) -> value) return false;

    if(value < (*root_ptr) -> value)
        return insert(&(*root_ptr)->left, value);
    else
        return insert(&(*root_ptr)->right, value);
}

bool find(TreeNode *root, int value){
    if(root == NULL) return false;
    if(root -> value == value) return true;

    if(root -> value > value)
        return find(root -> left, value);
    else
        return find(root -> right, value);
}

TreeNode *creat_node(int value){
    TreeNode* result = malloc(sizeof (TreeNode));
    if (result != NULL){
        result -> value = value;
        result -> left = NULL;
        result -> right = NULL;
    }
    return result;
}

void print_tree_rec(TreeNode *root, int level){
    if(root == NULL){
        print_tabs(level);
        printf("---<empty>---\n");
        return;
    }
    print_tabs(level);
    printf("value = %d\n", root -> value);

    print_tabs(level);
    printf("left\n");

    print_tree_rec(root -> left, level++);

    print_tabs(level);
    printf("right\n");

    print_tree_rec(root -> right, level++);

    print_tabs(level);
    printf("done!\n");
}




