#include "cashbox.h"

CashBox::CashBox()
{

}

int CashBox::addNotes(const std::string & currency, unsigned int value, unsigned int number)
{
    int errorKey = checkParams(currency, value, number);
    if(errorKey == 0)
    {
        errorKey = db.addNotes(currency, value, number);
    }
    return errorKey;
}

int CashBox::getCash(const std::string & currency, unsigned int value, unsigned int number)
{
    int errorKey = checkParams(currency, value, number);
    if(errorKey == 0)
    {
        errorKey = db.getCash(currency, value, number);
    }
    return errorKey;
}

int CashBox::checkParams(const std::string & currency, unsigned int value, unsigned int number)
{
    int errorKey = 0;
    if(currency.length() != 3 )
        errorKey = 1;
    if(value <= 0)
        errorKey = 2;
    if(number <= 0)
        errorKey = 3;
    return errorKey;
}

std::string CashBox::info()
{
    return db.info();
}
