#ifndef SEARCH_WORDS_H
#define SEARCH_WORDS_H

struct positions{
    int x_init;
    int y_init;
    int x_end;
    int y_end;
};

char* get_word(int m, int n);

bool find_horizontal_direct(int m, int n, char* requested_word, char** mat, struct positions* placement);

bool find_horizontal_reverse(int m, int n, char* requested_word, char** mat, struct positions* placement);

bool find_vertical_direct(int m, int n, char* requested_word, char** mat, struct positions* placement);

bool find_vertical_reverse(int m, int n, char* requested_word, char** mat, struct positions* placement);

bool find_primary_diagonal_direct(int m, int n, char* requested_word, char** mat, struct positions* placement);

bool find_primary_diagonal_reverse(int m, int n, char* requested_word, char** mat, struct positions* placement);

bool find_secondary_diagonal_direct(int m, int n, char* requested_word, char** mat, struct positions* placement);

bool find_secondary_diagonal_reverse(int m, int n, char* requested_word, char** mat, struct positions* placement);

void find_word(int m, int n, char* requested_word, char** mat);

#endif