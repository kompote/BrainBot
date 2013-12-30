#ifndef _NEURON_H
#define _NEURON_H

#include <vector>

typedef struct {
    std::vector<unsigned int> inputs;
    unsigned int output;
    unsigned char outThreshold;
    std::vector<unsigned int> inputsThresholds;
} neuron;

#endif
