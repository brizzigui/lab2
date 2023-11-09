#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "list.h"

// compilar usando "gcc main.c list.c -o main.exe"

Lista* read_values(Lista* identity_matrix, int order)
{
    printf("Preencha a matriz com os elementos desejados.\n");
    for (int i = 0; i < order; i++)
    {
        for (int j = 0; j < order; j++)
        {
            printf("Insira o valor de (%d, %d): ", i, j);

            int current_read;
            scanf("%d", &current_read);

            if (!((current_read == 1 && i == j) || (current_read == 0 && i != j)))
            {
                // ignora valores implícitos da matriz identidade
                // que não criam nós na lista
                identity_matrix = list_insert(identity_matrix, current_read, i, j);
            }
            
        }
        
    }

    printf("Matriz lida.\n\n");

    return identity_matrix;
}

bool is_identity_matrix(Lista* identity_matrix)
{
    if (identity_matrix == NULL)
    {
        return true;
    }

    return false;
}

void print_matrix(Lista* identity_matrix, int order)
{
    printf("Imprimindo matriz.\n\n");

    for (int i = 0; i < order; i++)
    {
        for (int j = 0; j < order; j++)
        {
            printf(" %d ", list_find_id_matrix_value(identity_matrix, i, j));            
        }

        printf("\n");
    }

    printf("\n");
}

int main()
{
    Lista* identity_matrix = list_create();

    int order;
    printf("Insira a ordem da matriz quadrada: ");
    scanf("%d", &order);

    identity_matrix = read_values(identity_matrix, order);
    print_matrix(identity_matrix, order);

    if (is_identity_matrix(identity_matrix))
    {
        printf("A matriz inserida corresponde a uma matriz identidade.\n");
    }

    else
    {
        printf("A matriz inserida NAO corresponde a uma matriz identidade.\n");
        list_print_violating_id_matrix_values(identity_matrix);
    }

    return 0; 
}
