#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "matrix.h"

int** create_matrix(int s){
    int** mat = (int**)malloc(s * sizeof(int*));
    for(int i=0; i<s; i++){
        mat[i] = (int*)malloc(s * sizeof(int));
    }
    return mat;
}

void fill_matrix(int** mat, int c){
    for(int i = 0; i < c; i++){
        for (int j = 0; j < c; j++){
            printf("Write a value for the coordinates %d %d: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}

void print_matrix(int** mat, int c){
    for (int i = 0; i < c; i++){
        if(i==0){
            printf("   ");
            for (int j = 0; j < c; j++)
            {
                printf("  %02d", j);
            }
            printf("\n\n");
            
        }
        for (int j = 0; j < c; j++){
            if(j==0){
                printf("%02d   ", i);
            }
            printf("%d   ", mat[i][j]);
        }
        printf("\n");
    }  
    printf("\n\n");  
}

void non_identity(int** mat, int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(j==i && mat[i][j] != 1){
                printf("Value at coordenates %d %d is different from 1 \n", i, j);
            }
            else if (j != i && mat[i][j] != 0){
                printf("Value at coordenates %d %d is non-zero \n", i, j);
            }
        }
    }
}

bool is_identity(int** mat, int order){
    bool is = true;
    for (int i = 0; i < order; i++){
        for (int j = 0; j < order; j++){
            if(i==j && mat[i][j] != 1 || j != i && mat[i][j] != 0){
                is = false;
            }
        }
    }
    return is;
}