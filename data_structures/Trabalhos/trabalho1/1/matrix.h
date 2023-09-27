#ifndef MATRIX_H
#define MATRIX_H

struct diagonal{
int ordem;
int* v;
}; typedef struct diagonal Diagonal;

int** create_matrix(int s);
void fill_matrix(int** mat, int c);
void print_matrix(int** mat, int c);
void search_matrix(int** mat, int i, int j);
int* allocate_vector(int s);
void store_diagonal(int** mat, int* v, int s);
void print_diagonal(int* v, int ordem);

#endif