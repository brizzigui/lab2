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

void search_matrix(int** mat, int i, int j){
    printf("%d ", mat[i][j]);
}

int* allocate_vector(int s){
    int* v = (int*)malloc(s * sizeof(int));
    return v;
}

void store_diagonal(int** mat, int* v, int s){
    for (int i = 0; i < s; i++){
        v[i] = mat[i][i];
    }
}

void print_diagonal(int* v, int ordem){
    printf("Matrix order: %d \n", ordem);
    printf("Elements of the diagonal: ");
    for (int i = 0; i < ordem; i++)
    {
        if(i == ordem-1){
            printf("%d", v[i]);
        }
        else{
            printf("%d, ", v[i]);
        }
    }
}