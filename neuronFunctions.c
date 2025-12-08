#include "headers/neuronFunctions.h"

neuron* initialiseNeuronLayer(uint8_t numberOfNeurons, neuronType type, float* biasArray) {
    neuron* newLayer = malloc(numberOfNeurons * sizeof(neuron));

    for (int i = 0; i < numberOfNeurons; i++) {
        newLayer[i].value = 0.0f;
        newLayer[i].bias = biasArray == NULL ? 0.0f : biasArray[i];
        newLayer[i].connections = NULL;
        newLayer[i].numberOfConnections = 0;
        newLayer[i].layerType = type;
    }

    return newLayer;
}

int createRandomWeightMatrix(uint8_t numberOfInputNeurons, uint8_t numberOfOutputNeurons, matrix* outMatrix) {
    if (outMatrix == NULL) {
        printf("outMatrix is NULL in %s, %s:%d\n", __func__, __FILE__, __LINE__);
        return 1;
    }

    INIT_MATRIX_FROM_POINTER(outMatrix, numberOfInputNeurons, numberOfOutputNeurons)

    srand( time(NULL) );

    for (int x = 0; x < numberOfInputNeurons; x++) {
        for (int y = 0; y < numberOfOutputNeurons; y++) {
            changeMatrixValue(outMatrix, x, y, GENERATE_RAND(1));
        }
    }
}
