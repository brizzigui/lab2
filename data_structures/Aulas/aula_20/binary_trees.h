#ifndef BINARY_TREES_H
#define BINARY_TREES_H

struct tree 
{
    int info;
    struct tree* left;
    struct tree* right;
};

typedef struct tree Tree;

Tree* binary_tree_create();
Tree* binary_tree_insert (Tree* tree, int v);
void binary_tree_print (Tree* tree);
Tree* binary_tree_search (Tree* tree, int v);
Tree* binary_tree_remove (Tree* tree, int v);

#endif