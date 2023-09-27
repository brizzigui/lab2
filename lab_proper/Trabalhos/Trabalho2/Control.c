#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#include "Search_words.h"
#include "Matrix.h"

int main(){
    int m, n;
    bool dontstop = true;
    printf("Write the numbers of lines that your matrix has: ");
    scanf("%d", &m);
    printf("Write the numbers of columns that your matrix has: ");
    scanf("%d", &n);
    
    char** matrix = createMatrix(m, n);
    fillMatrix(m,n,matrix);
    char* requested_word;

    while (dontstop){
        printMatrix(m,n,matrix);
        requested_word = get_word(m, n);
        find_word(m, n, requested_word, matrix);
        printf("Wanna search for another word? Type yes or no: ");
        char answer[32];
        scanf("%s", answer);
        strlwr(answer);

        if (answer[0] == 'n')
        {
            dontstop = !dontstop;
        }
    }
    
    freeMatrix(m, matrix);
    return 0;
}

