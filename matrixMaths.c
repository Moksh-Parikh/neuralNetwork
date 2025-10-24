#include "headers/matrixMaths.h"

void printVector(vector vectorA) {
    for (int i = 0; i < vectorA.size; i++) {
        printf("%d", vectorA.values[i]);
        if (i == vectorA.size - 1) {
            printf("\n");
        }
        else {
            printf(" ");
        }
    }

}

int changeMatrixValue(matrix* input, int row, int column, int value) {
    input->values[row * input->columns + column] = value;
    return 0;
}

int readMatrixValue(matrix input, int row, int column) {
    if (input.rows < row || input.columns < column) {
        printf("Out of bounds access in %s\nInput matrix is %d x %d, tried to access %d, %d", __func__, input.rows, input.columns, row, column);
        return 0;
    }
    return input.values[row * input.columns + column];
}

void printMatrix(matrix input) {
    for (int x = 0; x < input.rows; x++) {
        for (int y = 0; y < input.columns; y++) {
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

int dotProduct(vector vectorA, vector vectorB) {
    if (vectorA.size != vectorB.size) {
        printf("Vectors not of the same size!");
        return 0;
    }

    int dotProductResult = 0;

    for(int i = 0; i < vectorA.size; i++) {
        dotProductResult += vectorA.values[i] * vectorB.values[i];
    }

    return dotProductResult;
}

int multiplyMatrices(matrix matrixA, matrix matrixB, matrix* outMatrix) {
    if (matrixA.columns != matrixB.rows) {
        printf("Matrices are not multiplicable!\n");
        return 0;
    }

    INIT_MATRIX_FROM_POINTER(outMatrix, matrixA.rows, matrixB.columns)
    // outMatrix->values = malloc(matrixA.rows * matrixB.columns * sizeof(int));
    // outMatrix->columns = matrixB.columns;
    // outMatrix->rows = matrixA.rows;

    INIT_VECTOR(vector1, matrixA.columns)
    INIT_VECTOR(vector2, matrixB.rows)


    for (int x = 0; x < matrixA.rows; x++) {
        vector1.values = matrixA.values + (x * matrixA.columns);

        for (int y = 0; y < matrixB.columns; y++) {
            // printf("Filling vec2, (%d, %d)\n", x, y);
            for (int i = 0; i < vector2.size; i++) {
                vector2.values[i] = matrixB.values[(matrixB.columns * i) + y];
                printf("%d (accessing %d) ", vector2.values[i], (matrixB.rows * i) + y);
            }

            printf("\n\n");
            // // printf("(%d, %d)\n", x, y);

            printf("vect1: ");
            printVector(vector1);
            printf("\n");
            printf("vect2: ");
            printVector(vector2);
            printf("\n");

            int dotProd = dotProduct(vector1, vector2);
            // printf("dotProd = %d\n", dotProd);

            changeMatrixValue(outMatrix, x, y, dotProd);
            // printf("changed val = %d\n", readMatrixValue(*outMatrix, x, y) );
        }
    }

    printMatrix(*outMatrix);

    DESTROY_VECTOR(vector1);
    DESTROY_VECTOR(vector2);
}
