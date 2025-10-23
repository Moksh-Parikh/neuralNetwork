#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int* values;
    int rows;
    int columns;
} matrix;

int changeMatrixValue(matrix* input, int row, int column, int value);
int readMatrixValue(matrix input, int row, int column);
void printMatrix(matrix input);
