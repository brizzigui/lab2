#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "bstree.h"
#include "list.h"

Tree* create_tree_null(){
    return NULL;
}

Tree* return_by_code(Tree* a, int code){
    if(a != NULL){
        if(code > a->code){
            a = return_by_code(a->right, code);
        }
        else if(code < a->code){
            a = return_by_code(a->left, code);
        }
        else if(a->code == code){
            return a;
        }

    }

    return a;

}

void printnode(Tree* a){
    if(a != NULL){
        printf("Curso: %s \n", a->name);
        printf("\tCodigo: %d \n", a->code);
        printf("\tCentro: %s \n", a->center);
        print_list(a->students);
        printf("\n");
    }
}

void print_tree_ordered(Tree* a){
    if(a != NULL){
        print_tree_ordered(a->left);
        printnode(a);
        print_tree_ordered(a->right);
    }
}

void print_tree_codename(Tree* a){
    if(a != NULL){
        print_tree_codename(a->left);
        printf("Codigo: %d; Nome: %s \n", a->code, a->name);
        print_tree_codename(a->right);
    }
}

Tree* insert_tree(Tree* a){
    int cod;
    printf("Digite o codigo do curso que deseja inserir: ");
    scanf("%d", &cod);

    return insert_value(a, cod);
}

Tree* insert_value(Tree* a, int v){
    if(a == NULL){
        a = (Tree*)malloc(sizeof(Tree));
        printf("Digite o nome do curso: ");
        getchar();
        scanf("%[^\n]", a->name);
        printf("Digite o centro do curso: ");
        scanf("%s", a->center);
        a->students = create_list();
        a->code = v;

        a->left = a->right = create_tree_null();
    }
    else if(v < a->code){
        a->left = insert_value(a->left, v);
    }
    else{
        a->right = insert_value(a->right, v);
    }
    return a;
}

Tree* search_tree(Tree* a, int v){
    if (a == NULL){
        return NULL;
    }
    else if(a->code > v){
        search_tree(a->left, v);
    }
    else if(a->code < v){
        search_tree(a->right, v);
    }
    else{
        return a;
    }
}

Tree* remove_value(Tree* a, int v){
    if (a == NULL){
        return NULL;
    }
    else if(a->code > v){
        a->left = remove_value(a->left, v);
    }
    else if(a->code < v){
        a->right = remove_value(a->right, v);
    }
    else{
        if(a->left == NULL && a->right == NULL){
            free(a);
            a = NULL;
        }
        else if(a->left == NULL){
            Tree* ptr = a;
            a = a->right;
            free(ptr);
        }
        else if(a->right == NULL){
            Tree* ptr = a;
            a = a->left;
            free(ptr);
        }
        else{
            Tree* ptr = a->left;
            while(ptr->right != NULL){
                ptr = ptr->right;
            }
            a->code = ptr->code;
            ptr->code = v;
            a->left = remove_value(a->left, v);
        }
    }
    return a;
}

Tree* remove_node(Tree* a){
    int cod;
    print_tree_codename(a);
    printf("Digite o codigo do curso que deseja excluir: ");
    scanf("%d", &cod);

    Tree* ptr = return_by_code(a, cod);
    if(ptr == NULL)
    {
        printf("Digite um codigo valido. \n");
    }

    else
    {
        a = remove_value(a, cod);
    }

    return a;
}

void insert_student(Tree* a){
    int cd;
    print_tree_codename(a);
    printf("Digite o codigo do curso no qual deseja adicionar um aluno: ");
    scanf("%d", &cd);
    Tree* ptr = return_by_code(a, cd);
    if(ptr == NULL){
        printf("Digite um codigo valido. \n");
    }
    else{
        ptr->students = insert_list(ptr->students);
    }
}

void remove_student(Tree* a){
    int cd;
    print_tree_codename(a);
    printf("Digite o codigo do curso no qual deseja remover um aluno: ");
    scanf("%d", &cd);
    Tree* ptr = return_by_code(a, cd);
    if(ptr == NULL){
        printf("Digite um codigo valido. \n");
    }
    else{
        ptr->students = remove_from_list(ptr->students);
    }
}

void print_course(Tree* a){
    int cod;
    printf("Digite o codigo do curso que deseja imprimir: ");
    scanf("%d", &cod);
    
    printnode(return_by_code(a, cod));
}