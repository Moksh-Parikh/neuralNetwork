#include <stdio.h>
#include <stdlib.h>

#define INIT_VECTOR(newVector, numberOfValues) vector (newVector); \
            (newVector).size = (numberOfValues); \
            (newVector).values = malloc((numberOfValues) * sizeof(int));

#define INIT_MATRIX(newMatrix, rows, columns) matrix (newMatrix); \
            (newMatrix).rows = (rows); \
            (newMatrix).columns = (columns); \
            (newMatrix).values = malloc((rows) * (columns) * sizeof(int));

#define INIT_MATRIX_FROM_POINTER(newMatrix, newRows, newColumns) (newMatrix)->rows = (newRows); \
            (newMatrix)->columns = (newColumns); \
            (newMatrix)->values = malloc((newRows) * (newColumns) * sizeof(int));

#define DESTROY_VECTOR(oldVector) free((oldVector).values); \
                        (oldVector).values = NULL; \
                        (oldVector).size = 0;

#define DESTROY_MATRIX(oldMatrix) free((oldMatrix).values); \
                        (oldMatrix).values = NULL; \
                        (oldMatrix).rows = 0; \
                        (oldMatrix).columns = 0;

typedef struct {
    int* values;
    int size;
} vector;

typedef struct {
    int* values;
    int rows;
    int columns;
} matrix;

void printVector(vector vectorA);
int changeMatrixValue(matrix* input, int row, int column, int value);
int readMatrixValue(matrix input, int row, int column);
void printMatrix(matrix input);
int dotProduct(vector vectorA, vector vectorB);
int multiplyMatrices(matrix matrixA, matrix matrixB, matrix* outMatrix);
