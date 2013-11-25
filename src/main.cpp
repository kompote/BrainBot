#include <iostream>
#include "core/robot.h"
// ----------------------------------------------------------------- main
int main()
{
    std::cout<<"Create Robot..."<<std::endl;
    Robot robot;
    std::cout<<"Done."<<std::endl;
    robot.think();
    return 0;
}

