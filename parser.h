#ifndef PARSER_H
#define PARSER_H
#include <string>
#include "operation.h"

class Parser
{
public:
    Parser();
    int parce(const std::string &command, Operation &operation, std::string &currency);
};

#endif // PARSER_H
