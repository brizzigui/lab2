#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#include "binary_trees.h"

Tree* binary_tree_create()
{
    return NULL;
}

Tree* binary_tree_insert (Tree* tree, int v)
{
    if (tree == NULL)
    {
        tree = (Tree *)malloc(sizeof(Tree));
        tree->info = v;
        tree->left = NULL;
        tree->right = NULL;
    }

    else if (v < tree->info)
    {
        tree->left = binary_tree_insert(tree->left, v);
    }

    else 
    {
        tree->right = binary_tree_insert(tree->right, v);
    }

    return tree;
}

void binary_tree_print(Tree* tree)
{
    if (tree != NULL)
    {
        binary_tree_print(tree->left);
        printf(" %d ", tree->info);
        binary_tree_print(tree->right);
    }
}

Tree* binary_tree_search (Tree* tree, int v)
{
    if (tree == NULL)
    {
        return NULL;
    }

    if (tree->info == v)
    {
        return tree;
    }

    if (v < tree->info)
    {
        return binary_tree_search(tree->left, v);
    }

    if (v > tree->info)
    {
        return binary_tree_search(tree->right, v);
    }
}

Tree* binary_tree_remove (Tree* tree, int v)
{
    if (tree == NULL)
    {
        return NULL;
    }

    else if (tree->info > v)
    {
        tree->left = binary_tree_remove(tree->left, v);
    }

    else if (tree->info < v)
    {
        tree->right = binary_tree_remove(tree->right, v);
    }

    else 
    { /* achou o nó a remover */
      /* nó sem filhos */
        if (tree->left == NULL && tree->right == NULL) 
        {
            free (tree);
            tree = NULL;
        }

        /* nó só tem filho à righteita */
        else if (tree->left == NULL) 
        {
            Tree* t = tree;
            tree = tree->right;
            free (t);
        }

        /* só tem filho à leftuerda */
        else if (tree->right == NULL) 
        {
            Tree* t = tree;
            tree = tree->left;
            free (t);
        }
        
        /* nó tem os dois filhos */
        else 
        {
            Tree* f = tree->left;

            while (f->right != NULL) 
            {
                f = f->right;
            }

            tree->info = f->info; /* troca as informações */
            f->info = v;
            tree->left = binary_tree_remove(tree->left,v);
        }
    }
    
    return tree;
}

void print_decreasing_order(Tree* tree)
{
    if (tree == NULL)
    {
        return;
    }

    print_decreasing_order(tree->right);
    printf(" %d ", tree->info);
    print_decreasing_order(tree->left);    
}

bool is_binary_search_tree(Tree* tree)
{
    if (tree == NULL)
    {
        return true;
    }

    if (tree->left != NULL && tree->right != NULL)
    {
        return (tree->left->info <= tree->info) && (tree->right->info >= tree->info) &&
                is_binary_search_tree(tree->left) && is_binary_search_tree(tree->right);
    }

    else if (tree->left != NULL)
    {
        return (tree->left->info <= tree->info) &&
                is_binary_search_tree(tree->left) && is_binary_search_tree(tree->right);
    }
    
    else if (tree->right != NULL)
    {
        return (tree->right->info >= tree->info) &&
                is_binary_search_tree(tree->left) && is_binary_search_tree(tree->right);
    }

    return is_binary_search_tree(tree->left) && is_binary_search_tree(tree->right);
    
}

void invert_binary_tree(Tree* tree)
{
    if(tree == NULL)
    {
        return;
    }

    Tree* temp = tree->left;
    tree->left = tree->right;
    tree->right = temp;

    invert_binary_tree(tree->left);
    invert_binary_tree(tree->right);
    
}

void main()
{
    Tree* a = binary_tree_create();
    a = binary_tree_insert (a, 5);
    a = binary_tree_insert (a, 1);
    a = binary_tree_insert (a, 3);
    a = binary_tree_insert (a, 4);
    a = binary_tree_insert (a, 7);
    a = binary_tree_insert (a, 2);
    a = binary_tree_insert (a, 8);
    a = binary_tree_remove (a, 8);
    a = binary_tree_remove (a, 1);
    a = binary_tree_remove (a, 5);
    a = binary_tree_remove (a, 4);

    printf("kein seg fault, bitches!\n");

    printf("Printing elements of the tree in decreasing order: \n");
    print_decreasing_order(a);
    printf("\n");

    printf("Adding more elements to further test!\n");
    a = binary_tree_insert (a, 53);
    a = binary_tree_insert (a, 32);
    a = binary_tree_insert (a, 1);
    a = binary_tree_insert (a, -5);

    print_decreasing_order(a);
    printf("\n");

    printf("Is a binary search tree: %d\n", is_binary_search_tree(a));

    printf("Forcefully changing to break criteria!\n");
    int temp = a->info;
    a->info = -1000;

    printf("Is a binary search tree: %d\n", is_binary_search_tree(a));
    printf("Returning to original state.\n");

    a->info = temp;
    printf("Is a binary search tree: %d\n", is_binary_search_tree(a));

    printf("Inverting the tree!\n");
    invert_binary_tree(a);
    printf("Is a binary search tree: %d\n", is_binary_search_tree(a));
    printf("Current state of the tree : \n");
    print_decreasing_order(a);
    printf("\n");


}
