#include "db.h"

DB::DB()
{

}
int DB::checkParams(const std::string & currency, unsigned int value, unsigned int number)
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
int DB::addNotes(const std::string & currency, unsigned int value, unsigned int number)
{
    int errorKey = checkParams(currency, value, number);
    if(errorKey == 0)
    {
        cash[currency][value] +=  number;
    }
    return errorKey;
}

int DB::getCash(const std::string & currency, unsigned int value, unsigned int number)
{
    int errorKey = checkParams(currency, value, number);
    if(errorKey == 0)
    {
        auto currency_it = cash.find(currency);
        if(currency_it != cash.end())
        {
            auto value_it = (currency_it->second).find(value);
            if(value_it != (currency_it->second).end())
            {
                if(value_it->second >= number)
                {
                    value_it->second -=  number;
                }
                else
                {
                    errorKey = -3;
                }
            }
            else
            {
                errorKey = -2;
            }
        }
        else {
            errorKey = -1;
        }
    }
    return errorKey;
}

std::string DB::info()
{
    std::string info = "";
    for(auto currPair : cash)
    {
        for(auto valNumberPair : currPair.second)
        {
            char buf[50];
            sprintf_s(buf, 50, "%s %d &d \n",currPair.first, valNumberPair.first, valNumberPair.second);
            info += buf;
        }
    }
    return info;
}
