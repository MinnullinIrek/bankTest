#ifndef CASHBOX_H
#define CASHBOX_H

#include "db.h"

class CashBox
{
    DB db;
    int checkParams(const std::string & currency, unsigned int value, unsigned int number);
public:
    CashBox();
    int addNotes(const std::string & currency, unsigned int value, unsigned int number);
    int getCash(const std::string & currency, unsigned int value, unsigned int number);
    std::string info();
};

#endif // CASHBOX_H
