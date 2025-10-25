#include "headers/matrixMaths.h"

int main() {
    INIT_MATRIX(matrix1, 2, 2)
    INIT_MATRIX(matrix2, 2, 2)

    matrix matrix3;
    
    for (int x = 0; x < 2; x++) {
        for (int y = 0; y < 2; y++) {
            changeMatrixValue(&matrix1, x, y, x+y);
            changeMatrixValue(&matrix2, y, x, x+y);
        }
    }

    printMatrix(matrix1);
    printf("\n");

    printMatrix(matrix2);
    printf("\n");

    multiplyMatrices(matrix1, matrix2, &matrix3);
    printMatrix(matrix3);
    
    DESTROY_MATRIX(matrix1);
    DESTROY_MATRIX(matrix2);
    DESTROY_MATRIX(matrix3);

    // printf("hi\n");
    return 0;
}
