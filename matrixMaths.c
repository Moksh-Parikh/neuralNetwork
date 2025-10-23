#include "matrixMaths.h"

int changeMatrixValue(matrix* input, int row, int column, int value) {
    input->values[row * input->columns + column] = value;
    return 0;
}

int readMatrixValue(matrix input, int row, int column) {
    if (input.rows < row || input.columns < column) {
        printf("Out of bounds access in %s", __func__);
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
