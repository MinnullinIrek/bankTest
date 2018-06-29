#include "parser.h"


Parser::Parser()
{

}

int Parser::parce(const std::string &command, Operation& operation, std::string &currency)
{
    if(command.length() < 4)
    {
        return -1;
    }

    if(command[0] == '+')
        operation = Operation::addCash;
    else if(command[0] == '-')
        operation = Operation::getCash;
    else if(command[0] == '?')
        operation = Operation::question;
    else
        return -3;

    currency = command.substr(1, 3);


    return 0;
}
