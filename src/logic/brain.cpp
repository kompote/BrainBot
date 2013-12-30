#include <iostream>
#include "brain.h"

#include "AI-1/reflexsystem.h"

Brain::Brain()
{
}

Brain::~Brain()
{}

void Brain::think()
{
    std::cout<<"Thinking..."<<std::endl;
    ReflexSystem RS;
    RS.evaluateL1();
    RS.evaluateL2();
    RS.evaluateL3();
}
