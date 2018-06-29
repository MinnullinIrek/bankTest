#ifndef BANK_H
#define BANK_H

#include <string>

#include "parser.h"
#include "io.h"
#include "cashbox.h"

class Bank
{
    IO io;
    Parser parser;
    CashBox cashBox;

    std::string errorMsg = "Error";
    std::string okMsg = "Ok";


    int getCommand();
    int putResponse(const std::string & response);
    int parseCommand();

    int checkCommand(const std::string & command);
    int addNotes(const std::string & currency);
    int getCash(const std::string & currency);
    void info();
public:
    Bank();
    int cicle();


};

#endif // BANK_H
