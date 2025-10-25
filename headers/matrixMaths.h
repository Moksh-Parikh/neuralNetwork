#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define INIT_VECTOR(newVector, numberOfValues) vector (newVector); \
            (newVector).size = (numberOfValues); \
            (newVector).values = malloc((numberOfValues) * sizeof(int32_t));

#define INIT_MATRIX(newMatrix, mRows, mColumns) matrix (newMatrix); \
            (newMatrix).rows = (mRows); \
            (newMatrix).columns = (mColumns); \
            (newMatrix).values = malloc((mRows) * (mColumns) * sizeof(int32_t));

#define INIT_MATRIX_FROM_POINTER(newMatrix, newRows, newColumns) (newMatrix)->rows = (newRows); \
            (newMatrix)->columns = (newColumns); \
            (newMatrix)->values = malloc((newRows) * (newColumns) * sizeof(int32_t));

#define DESTROY_VECTOR(oldVector) free((oldVector).values); \
                        (oldVector).values = NULL; \
                        (oldVector).size = 0;

#define DESTROY_MATRIX(oldMatrix) free((oldMatrix).values); \
                        (oldMatrix).values = NULL; \
                        (oldMatrix).rows = 0; \
                        (oldMatrix).columns = 0;

typedef struct {
    int32_t* values;
    int32_t size;
} vector;

typedef struct {
    int32_t* values;
    int32_t rows;
    int32_t columns;
} matrix;

typedef enum {
    NOT_MULTIPLICABLE,
    MEMORY_ERROR
} matrixMultiplicationErrorTypes;

void printVector(vector vectorA);
void changeMatrixValue(matrix* input, int32_t row, int32_t column, int32_t value);
int32_t readMatrixValue(matrix input, int32_t row, int32_t column);
void printMatrix(matrix input);
int32_t dotProduct(vector vectorA, vector vectorB);
matrixMultiplicationErrorTypes multiplyMatrices(matrix matrixA, matrix matrixB, matrix* outMatrix);
