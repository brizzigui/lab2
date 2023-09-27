#ifndef MATRIX_H
#define MATRIX_H

void zeroAtEnd(int m, int n, char** mat);

char** createMatrix(int m, int n);

void printMatrix(int m, int n, char** mat);

void fillMatrix(int m, int n, char** mat);

void freeMatrix(int m, char** mat);

#endif