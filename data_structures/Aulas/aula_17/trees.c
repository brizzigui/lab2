#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#include "trees.h"

Tree* tree_create_empty()
{
    return NULL;
}

Tree* tree_create(int info, Tree* left, Tree* right)
{
    Tree *parent = (Tree *)malloc(sizeof(Tree));
    parent->info = info;
    parent->left = left;
    parent->right = right;

    return parent;
}

Tree* tree_free(Tree* tree)
{
    if (tree != NULL)
    {   
        tree_free(tree->left);
        tree_free(tree->right);
        free(tree);
    }

    return NULL;
}

bool tree_is_empty(Tree* tree)
{
    return tree == NULL;
}

bool tree_find(Tree* tree, int info)
{
    if (tree == NULL)
    {
        return false;
    }

    return tree->info == info ||
           tree_find(tree->left, info) ||
           tree_find(tree->right, info);
}

void tree_print(Tree* tree)
{
    printf(" <");
    if(tree != NULL)
    {
        printf("%d", tree->info);
        tree_print(tree->left);
        tree_print(tree->right);
    }

    printf("> ");
}


// aula 17 - questão 1 - parte B
void tree_print_pre_order(Tree* tree)
{
    if(tree != NULL)
    {
        printf(" %c ", tree->info);
        tree_print_pre_order(tree->left);
        tree_print_pre_order(tree->right);
    }
}

void tree_print_symmetrical_order(Tree* tree)
{
    if(tree != NULL)
    {
        tree_print_symmetrical_order(tree->left);
        printf(" %c ", tree->info);
        tree_print_symmetrical_order(tree->right);
    }
}

void tree_print_post_order(Tree* tree)
{
    if(tree != NULL)
    {
        tree_print_post_order(tree->left);
        tree_print_post_order(tree->right);
        printf(" %c ", tree->info);
    }
}


// aula 17 - questão 2

int amount_of_even_numbers(Tree* tree)
{
    if (tree == NULL)
    {
        return false;
    }
    
    return ((tree->info % 2) == 0) +
           amount_of_even_numbers(tree->left) + 
           amount_of_even_numbers(tree->right);
}


Tree* tree_copy(Tree* tree)
{
    if(tree != NULL)
    {
        Tree *new = tree_create(tree->info, tree_copy(tree->left), tree_copy(tree->right));
        return new;
    }

    return tree;
}

int tree_count_leaves(Tree *tree)
{
    if (tree == NULL)
    {
        return false;
    }

    if (tree->left == NULL && tree->right == NULL)
    {
        return true;
    }
    
    return tree_count_leaves(tree->left) +
           tree_count_leaves(tree->right);
}


int single_child_nodes(Tree *tree)
{
    if(tree == NULL)
    {
        return 0;
    }

    return ((tree->left == NULL) ^ (tree->right == NULL)) + single_child_nodes(tree->left) + single_child_nodes(tree->right);
}

bool are_trees_equal(Tree *tree_A, Tree *tree_B)
{
    if ((tree_A == NULL) ^ (tree_B == NULL))
    {
        return false;
    }

    if (tree_A == NULL && tree_B == NULL)
    {
        return true;
    } 
    
    return tree_A->info == tree_B->info &&
           are_trees_equal(tree_A->left, tree_B->left) &&
           are_trees_equal(tree_A->right, tree_B->right);
}

void main()
{
    Tree *juche_doctrin = tree_create_empty();
    juche_doctrin = tree_create('A', tree_create_empty(), 
                    tree_create('B', tree_create_empty(), 
                    tree_create('C', 
                    tree_create('D', tree_create('E',
                    tree_create('G', tree_create('I', tree_create_empty(), tree_create_empty()), tree_create_empty()), tree_create_empty()),
                    tree_create('F', tree_create_empty(), 
                    tree_create('H', tree_create('J', tree_create_empty(), tree_create_empty()), tree_create_empty()))), tree_create_empty())));

                    
    printf("Found: %d\n", tree_find(juche_doctrin, 'A'));
    printf("Found: %d\n", tree_find(juche_doctrin, 'S'));

    tree_print(juche_doctrin);
    printf("\n");

    printf("Printing tree in pre-order: \n");
    tree_print_pre_order(juche_doctrin);
    printf("\n");


    printf("Printing tree in symmetrical order: \n");
    tree_print_symmetrical_order(juche_doctrin);
    printf("\n");

    printf("Printing tree in post-order: \n");
    tree_print_post_order(juche_doctrin);
    printf("\n");

    printf("Criando nova arvore\n");
    Tree *betrayers_of_stalin = tree_create(1, 
                                tree_create(2, tree_create_empty(), tree_create_empty()),
                                tree_create(3, tree_create_empty(), tree_create(4, tree_create_empty(), tree_create(6, tree_create_empty(), tree_create_empty()))));

    printf("There are %d even numbers in the tree given.\n", amount_of_even_numbers(betrayers_of_stalin));

    Tree *guardians_of_socialism = tree_copy(betrayers_of_stalin);
    printf("Original tree: \n");
    tree_print(betrayers_of_stalin);
    printf("\n");

    printf("Copied tree: \n");
    tree_print(guardians_of_socialism);
    printf("\n");

    printf("Lets do some leaf counting!\n");
    tree_print(juche_doctrin);
    printf("\n");
    printf("This tree has: %d leaf nodes.\n", tree_count_leaves(juche_doctrin));

    printf("Lets do some single child node counting!\n");
    tree_print(juche_doctrin);
    printf("\n");
    printf("This tree has: %d nodes with just 1 child node.\n", single_child_nodes(juche_doctrin));

    printf("Let's see if some trees are equal!\n");
    tree_print(juche_doctrin);
    printf("\n");
    tree_print(guardians_of_socialism);
    printf("\n");
    printf("The previous trees are equal: %d\n", are_trees_equal(juche_doctrin, guardians_of_socialism));

    tree_print(betrayers_of_stalin);
    printf("\n");
    tree_print(guardians_of_socialism);
    printf("\n");
    printf("The previous trees are equal: %d\n", are_trees_equal(betrayers_of_stalin, guardians_of_socialism));

}
