#ifndef NEURON_FUNCTIONS
#define NEURON_FUNCTIONS

#include "matrixMaths.h"
#include <time.h>

#define GENERATE_RAND(max) (float)rand()/(float)(RAND_MAX/(max))

typedef enum {
    INPUT_NEURON,
    HIDDEN_NEURON,
    OUTPUT_NEURON
} neuronType;

typedef struct neuron {
    float value;
    float bias;
    struct neuron* connections;
    uint8_t numberOfConnections;
    neuronType layerType;
    float* weightArray; // must be of size equal to numberOfConnections
} neuron;

neuron* initialiseNeuronLayer(uint8_t numberOfNeurons, neuronType type, float* biasArray);
int createWeightMatrix(uint8_t numberOfInputNeurons, uint8_t numberOfOutputNeurons, matrix* outMatrix);

#endif
