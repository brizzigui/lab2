#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "bstree.h"
#include "list.h"

// compile using "gcc control.c bstree.c list.c -o control.exe"

void menu(Tree* courses){
    int choice;
    do{
        printf("\nMenu de controle da arvore de cursos: \n");
        printf("1 - Inserir um curso na arvore; \n");
        printf("2 - Excluir um curso da arvore; \n");
        printf("3 - Impressao ordenado dos cursos; \n");
        printf("4 - Inserir aluno em um curso; \n");
        printf("5 - Excluir aluno de um curso; \n");
        printf("6 - Imprimir alunos de um curso; \n");
        printf("7 - Impressao de todas informacoes; \n");
        printf("10 - Sair. \n");
        printf("\n");

        printf("Sua escolha: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            courses = insert_tree(courses);
            break;
        
        case 2:
            courses = remove_node(courses);
            break;

        case 3:
            print_tree_codename(courses);
            break;

        case 4:
            insert_student(courses);
            break;

        case 5:
            remove_student(courses);
            break;

        case 6:
            print_course(courses);
            break;

        case 7:
            print_tree_ordered(courses);
            break;

        case 10:
            break;

        default:
            printf("Insira um valor valido. \n");
            break;
        }

    }while(choice != 10);

}

int main(){
    system("clear || cls");
    
    Tree* courses = create_tree_null();
    menu(courses);

    return 0;
}
