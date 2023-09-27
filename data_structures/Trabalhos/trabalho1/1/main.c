#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "matrix.h"

int main(){
    Diagonal diag;

    printf("Write the size of the matrix: ");
    scanf("%d", &diag.ordem);

    diag.v = allocate_vector(diag.ordem);
    int** mat = create_matrix(diag.ordem);

    fill_matrix(mat, diag.ordem);
    print_matrix(mat, diag.ordem);

    store_diagonal(mat, diag.v, diag.ordem);
    print_diagonal(diag.v, diag.ordem);

    return 0;
}
