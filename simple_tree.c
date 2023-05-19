#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode *creat_node(int value){
    TreeNode* result = malloc(sizeof (TreeNode));
    if (result != NULL){
        result -> value = value;
        result -> left = NULL;
        result -> right = NULL;
    }
    return result;
}

void print_tabs(int level){
    for (int i = 0; i < level; ++i)
        printf("\t\t");
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

void print_tree(TreeNode *root){
    print_tree_rec(root, 0);
}

int main(){
    TreeNode *root = creat_node(5);
    TreeNode *left = creat_node(6);
    TreeNode *right = creat_node(9);
    root -> left = left;
    root -> right = right;

    print_tree(root);

    free(root);
    free(left);
    free(right);




    return 0;
}