#include "headers/matrixMaths.h"

void printVector(vector vectorA) {
    for (int32_t i = 0; i < vectorA.size; i++) {
        printf("%d", vectorA.values[i]);
        if (i == vectorA.size - 1) {
            printf("\n");
        }
        else {
            printf(" ");
        }
    }

}

void changeMatrixValue(matrix* input, int32_t row, int32_t column, int32_t value) {
    input->values[row * input->columns + column] = value;
}

int32_t readMatrixValue(matrix input, int32_t row, int32_t column) {
    if (input.rows < row || input.columns < column) {
        printf("Out of bounds access in %s\n\tInput matrix is %d x %d, tried to access %d, %d", __func__, input.rows, input.columns, row, column);
        return 0;
    }
    return input.values[row * input.columns + column];
}

void printMatrix(matrix input) {
    for (int32_t x = 0; x < input.rows; x++) {
        for (int32_t y = 0; y < input.columns; y++) {
            printf("%d", readMatrixValue(input, x, y));

            if (y == input.columns - 1) {
                printf("\n");
            }
            else {
                printf(" ");
            }
        }
    }
}

int32_t dotProduct(vector vectorA, vector vectorB) {
    if (vectorA.size != vectorB.size) {
        printf("Vectors not of the same size!");
        return 0;
    }

    int32_t dotProductResult = 0;

    for(int32_t i = 0; i < vectorA.size; i++) {
        dotProductResult += vectorA.values[i] * vectorB.values[i];
    }

    return dotProductResult;
}

matrixMultiplicationErrorTypes multiplyMatrices(matrix matrixA, matrix matrixB, matrix* outMatrix) {
    if (matrixA.columns != matrixB.rows) {
        printf("Matrices are not multiplicable!\n");
        return NOT_MULTIPLICABLE;
    }

    INIT_MATRIX_FROM_POINTER(outMatrix, matrixA.rows, matrixB.columns)
    if (outMatrix->values == NULL) {
        printf("malloc error in %s, %s:%d\n", __func__, __FILE__, __LINE__);
        return MEMORY_ERROR;
    }

    vector vector1;
    vector1.values = NULL;
    // we don't allocate memory because .values will point to a section of memory in matrixA.values
    vector1.size = matrixA.columns;
    
    INIT_VECTOR(vector2, matrixB.rows)
    if (vector2.values == NULL) {
        printf("malloc error in %s, %s:%d\n", __func__, __FILE__, __LINE__);
        return MEMORY_ERROR;
    }

    for (int32_t x = 0; x < matrixA.rows; x++) {
        vector1.values = matrixA.values + (x * matrixA.columns);

        for (int32_t y = 0; y < matrixB.columns; y++) {
            for (int32_t i = 0; i < vector2.size; i++) {
                vector2.values[i] = matrixB.values[(matrixB.columns * i) + y];
            }

            int32_t dotProd = dotProduct(vector1, vector2);

            changeMatrixValue(outMatrix, x, y, dotProd);
        }
    }

    // vector1.values is a section of matrixA.values, which is stack memory
    // so we don't need to free it
    DESTROY_VECTOR(vector2);
}
