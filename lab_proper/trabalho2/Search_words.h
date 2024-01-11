#ifndef SEARCH_WORDS_H
#define SEARCH_WORDS_H

struct positions{
    int x_init;
    int y_init;
    int x_end;
    int y_end;
};

char* get_word(int m, int n);

void find_word(int m, int n, char* requested_word, char** mat);

#endif