#include "io.h"
#include <iostream>

IO::IO()
{

}

int IO::getCommand(std::string &command)
{
    std::cin >> command;
    return 0;
}
int IO::getValue(int value)
{
    std::cin>>value;
    return 0;
}

int IO::putResponse(const std::string &messsage)
{
    std::cout<<messsage;
    return 0;
}
