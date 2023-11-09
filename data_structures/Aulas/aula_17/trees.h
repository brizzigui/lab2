#ifndef TREES_H
#define TREES_H

struct tree {
    int info;
    struct tree* left;
    struct tree* right;
};

typedef struct tree Tree;

Tree* tree_create_empty();
Tree* tree_create(int info, Tree* left, Tree* right);
Tree* tree_free(Tree* tree);
bool tree_is_empty(Tree* tree);
bool tree_find(Tree* tree, int info);
void tree_print(Tree* tree);

#endif