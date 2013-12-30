#ifndef _REFLEXSYSTEM_H
#define _REFLEXSYSTEM_H

#include <vector>
#include "neuron.h"

#define L1_SIZE 10
#define L2_SIZE 6
#define L3_SIZE 4

#define NB_SENSORS 8

class ReflexSystem
{
    private:
    std::vector<neuron> neuronsList;
    unsigned int neuronsL1[L1_SIZE];
    unsigned int neuronsL2[L2_SIZE];
    unsigned int neuronsL3[L3_SIZE];

    unsigned char m_input[NB_SENSORS];
    protected:
    public:
    ReflexSystem();
    ~ReflexSystem();
    unsigned char evaluateL1();
    unsigned char evaluateL2();
    unsigned char evaluateL3();


};

#endif
