#include "headers/neuronFunctions.h"

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

    multiplyMatrices(matrix1, matrix2, &matrix3);
    
    DESTROY_MATRIX(matrix1);
    DESTROY_MATRIX(matrix2);
    DESTROY_MATRIX(matrix3);

    float* biasArray = malloc(20 * sizeof(float));
    for (int i = 0; i < 20; i++) {
        biasArray[i] = (float)i / 43.7f;
    }

    neuron* inputLayer = initialiseNeuronLayer(10, INPUT_NEURON, NULL);
    neuron* hiddenLayer = initialiseNeuronLayer(20, HIDDEN_NEURON, biasArray);

    for (int i = 0; i < 20; i++) {
        printf("%f\n", hiddenLayer[i].bias);
    }

    free(biasArray);
    free(inputLayer);
    free(hiddenLayer);

    createRandomWeightMatrix(10, 20, &matrix3);

    printMatrix(matrix3);

    DESTROY_MATRIX(matrix3);

    INIT_MATRIX(transposeMePLZ, 3, 3)

    transposeMePLZ.values[0] = 1;
    transposeMePLZ.values[1] = 0;
    transposeMePLZ.values[2] = 1;
    transposeMePLZ.values[3] = 0;
    transposeMePLZ.values[4] = 1;
    transposeMePLZ.values[5] = 1;
    transposeMePLZ.values[6] = 0;
    transposeMePLZ.values[7] = 0;
    transposeMePLZ.values[8] = 1;

    printMatrix(transposeMePLZ);
    printf("\n");

    transposeMatrix(&transposeMePLZ);
    printMatrix(transposeMePLZ);
    printf("\n");
    DESTROY_MATRIX(transposeMePLZ);

    return 0;
}
