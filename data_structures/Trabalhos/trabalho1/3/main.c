#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "matrix.h"

int main(){
    int order;
    bool isIdentity;

    printf("Write the order of the matrix: ");
    scanf("%d", &order);

    int** mat = create_matrix(order);

    fill_matrix(mat, order);
    print_matrix(mat, order);

    isIdentity = is_identity(mat, order);
    if(isIdentity == false){
        printf("This matrix is not a identity matrix\n");
        non_identity(mat, order);
    }
    else{
        printf("The matrix is a identity matrix\n");
    }

    return 0;
}
