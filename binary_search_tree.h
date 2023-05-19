#ifndef TREE_IN_C_BINARY_SEARCH_TREE_H
#define TREE_IN_C_BINARY_SEARCH_TREE_H

#include <stdbool.h>

typedef struct TreeNode{
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode *creat_node(int value);

void print_tree_rec(TreeNode *root, int level);

void print_tree(TreeNode *root){ print_tree_rec(root, 0); }

void print_tabs(int level){ for (int i = 0; i < level; ++i) printf("\t\t"); }

bool insert(TreeNode **root_ptr, int value);

bool find(TreeNode *root, int value);

#endif //TREE_IN_C_BINARY_SEARCH_TREE_H
