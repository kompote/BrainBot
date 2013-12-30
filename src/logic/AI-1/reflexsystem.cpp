#include "reflexsystem.h"
#include "neuron.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

ReflexSystem::ReflexSystem()
{
    srand(time(NULL));

    for(int i = 0; i < L1_SIZE + L2_SIZE + L3_SIZE + 1 ; i++)
    {
        neuronsList.push_back(neuron());
    //    neuronsList[i].inputsThresholds.push_back(rand()%100);
    }


    for(int i = 0; i < L1_SIZE ; i++)
    {
        neuronsL1[i] = i + 1;
        for (int j = 0; j < 8; j++)
            neuronsList[neuronsL1[i]].inputsThresholds.push_back(rand()%100);
            //neuronsList[neuronsL1[i]].inputs.push_back(0);
    }
    for(int i = 0 ; i <  L2_SIZE  ; i++)
    {
        neuronsL2[i] = L1_SIZE + i + 1;
        for (int j = 0; j < L1_SIZE; j++)
        {
            neuronsList[neuronsL2[i]].inputs.push_back(neuronsL1[j]);
            neuronsList[neuronsL2[i]].inputsThresholds.push_back(rand()%100);
        }
    }

    for(int i = 0; i <  L3_SIZE ; i++)
    {
        neuronsL3[i] = L1_SIZE + L2_SIZE + i + 1 ;
        for (int j = 0; j < L3_SIZE; j++)
        {
            neuronsList[neuronsL3[i]].inputs.push_back(neuronsL2[j]);
            neuronsList[neuronsL3[i]].inputsThresholds.push_back(rand()%100);
        }
    }
    printf("input : [");
    for (int i = 0; i < NB_SENSORS; i++)
    {
        m_input[i] = rand()%2;
        printf("%d", m_input[i]);
    }
    printf("]\n");
}

ReflexSystem::~ReflexSystem()
{
}

unsigned char ReflexSystem::evaluateL1()
{
    neuron* current;
    printf("\n");
    for (int i = 0; i < L1_SIZE; i++)
    {
        unsigned int tmp = 0;
        current = &neuronsList[neuronsL1[i]];
        for (int j = 0; j < NB_SENSORS; j++)
            tmp += current->inputsThresholds[j] * m_input[j];
        current->output = tmp / NB_SENSORS;
        printf("L1 neuron %d : current = %d\n", i, current->output);
    }
    return 0;
}

unsigned char ReflexSystem::evaluateL2()
{
    neuron* current;
    printf("\n");
    for (int i = 0; i < L2_SIZE; i++)
    {
        unsigned int tmp = 0;
        current = &neuronsList[neuronsL2[i]];
        for (int j = 0; j < current->inputs.size(); j++)
            tmp += current->inputsThresholds[j] * neuronsList[current->inputs[j]].output;
        current->output = tmp / (current->inputs.size());
        printf("L2 neuron %d : current = %d\n", i, current->output);
    }
    return 0;
}

unsigned char ReflexSystem::evaluateL3()
{
    neuron* current;
    printf("\n");
    for (int i = 0; i < L3_SIZE; i++)
    {
        unsigned int tmp = 0;
        current = &neuronsList[neuronsL3[i]];
        for (int j = 0; j < current->inputs.size(); j++)
            tmp += current->inputsThresholds[j] * neuronsList[current->inputs[j]].output;
        current->output = tmp / current->inputs.size();
        printf("L3 neuron %d : current = %d\n", i, current->output);
    }
    return 0;
}
