#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void zeroAtEnd(int m, int n, char** mat){

    for (int i = 0; i < m; i++){
        mat[i][n] = '\0';
    }
    
}

char** createMatrix(int m, int n){
    char** mat = (char**)malloc(m * sizeof(char*));
    for (int i = 0; i < m; i++){
        mat[i] = (char*)malloc((n + 1) * sizeof(char));
    }
    zeroAtEnd(m, n, mat);
    return mat;
}

void printMatrix(int m, int n, char** mat){
    printf("Your word formed the following matrix:\n");
    printf("\n");
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("%c", mat[i][j]);
        }
        printf("\n");
    }    
}

void fillMatrix(int m, int n, char** mat){
    char* vect = (char*)malloc((m * n + 1) * sizeof(char));
    char* auxvect  = (char*)malloc((m * n + 1) * sizeof(char));
    int count = 0;
    printf("Write the characters to fill up the matrix: ");
    scanf(" %[^\n]", auxvect);
    for (int i = 0; count < m*n; i++){
        if(auxvect[i] != ' '){
            vect[count]=auxvect[i];
            count++;
        }
    }
    vect[count] = '\0';
    printf("%s", vect);

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (i*n + j > count){ // para não ler onde tem lixo
                mat[i][j]=' ';
            }
            
            else{
                mat[i][j]=vect[i * n + j];
            }
            
        }
    }
}