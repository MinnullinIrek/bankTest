#ifndef IO_H
#define IO_H
#include <string>


class IO
{
public:
    IO();
    int getCommand(std::string &command);
    int getValue(int value);
    int putResponse(const std::string &messsage);
};

#endif // IO_H
