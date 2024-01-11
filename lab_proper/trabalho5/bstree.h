#ifndef BS_TREE_H
#define BS_TREE_H

#include "list.h"

struct tree{
    int code;
    char name[64];
    char center[32];
    List* students;
    struct tree* left;
    struct tree* right;
};
typedef struct tree Tree;

Tree* create_tree_null();
void print_tree_codename(Tree* a);
Tree* insert_tree(Tree* a);
Tree* search_tree(Tree* a, int v);
Tree* remove_node(Tree* a);
void insert_student(Tree* a);
void remove_student(Tree* a);
void print_tree_ordered(Tree* a);
Tree* insert_value(Tree* a, int v);
void print_course(Tree* a);


#endif