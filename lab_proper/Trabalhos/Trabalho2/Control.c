#include <stdio.h>
#include <stdlib.h>
#include "Matrix.c"
#include "Search_words.c"

int main(){
    int m, n;
    printf("Write the numbers of lines that your matrix has: ");
    scanf("%d", &m);
    printf("Write the numbers of columns that your matrix has: ");
    scanf("%d", &n);
    
    char** matrix = createMatrix(m, n);
    fillMatrix(m,n,matrix);
    printMatrix(m,n,matrix);

    char* requested_word = get_word(m, n);
    find_word(m, n, requested_word, matrix);

    return 0;
}