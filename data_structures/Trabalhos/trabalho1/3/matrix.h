#ifndef MATRIX_H
#define MATRIX_H

int** create_matrix(int s);
void fill_matrix(int** mat, int c);
void print_matrix(int** mat, int c);
void non_identity(int** mat, int n);
bool is_identity(int** mat, int order);

#endif