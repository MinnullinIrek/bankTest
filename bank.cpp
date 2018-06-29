#include "bank.h"
#include "operation.h"


Bank::Bank()
{

}

int Bank::checkCommand(const std::string & command)
{
    return 0;

}
int Bank::addNotes(const std::string & currency)
{
    unsigned int value = 0;
    unsigned int number = 0;

    if(io.getValue(value) == 0)
    {
        if(io.getValue(number) == 0)
        {
            return cashBox.addNotes(currency, value, number);
        }
        else
            return -2;
    }
    else
        return - 1;


}

int Bank::getCash(const std::string & currency)
{
    unsigned int value = 0;
    unsigned int number = 0;
    if(io.getValue(value) == 0)
    {
        if(io.getValue(number) == 0)
        {
            return cashBox.getCash(currency, value, number);
        }
        else
            return -2;
    }
    else
        return - 1;
    return cashBox.getCash(currency, value, number);
}

void Bank::info()
{
    std::string info = cashBox.info();
    io.putResponse(info);
}

int Bank::cicle()
{
    while (true) {
        std::string command;
        int errorKey = io.getCommand(command);

        if(errorKey == 0)
        {
            errorKey = checkCommand(command);
            if(errorKey == 0)
            {
                std::string currency;

                Operation operation;
                errorKey = parser.parce(command,  operation, currency);
                if(errorKey == 0)
                {

                    switch (operation) {
                    case Operation::addCash:
                        errorKey = addNotes(currency);

                        break;
                    case Operation::getCash:
                        errorKey = getCash(currency);
                        break;
                    case Operation::question:
                        info();
                        break;

                    default:
                        break;
                    }
                }
            }

        }



    if(errorKey == 0)
        io.putResponse(okMsg);
    else
        io.putResponse(errorMsg);
    }
}
