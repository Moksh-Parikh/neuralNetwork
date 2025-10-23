#include "matrixMaths.h"

int main() {
    matrix matrix1;
    matrix1.values = malloc(4 * sizeof(int));
    matrix1.rows = 2;
    matrix1.columns = 2;

    for (int x = 0; x < 2; x++) {
        for (int y = 0; y < 2; y++) {
            changeMatrixValue(&matrix1, x, y, x*y);
        }
    }

    printMatrix(matrix1);

    free(matrix1.values);

    printf("hi\n");
    return 0;
}
