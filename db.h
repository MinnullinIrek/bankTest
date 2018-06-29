#ifndef DB_H
#define DB_H
#include <unordered_map>
#include <string>

class DB
{
private:
    std::unordered_map<std::string, std::unordered_map<unsigned int, unsigned int> > cash;
    int checkParams(const std::string & currency, unsigned int value, unsigned int number);
public:
    DB();
    int addNotes(const std::string & currency, unsigned int value, unsigned int number);
    int getCash(const std::string & currency, unsigned int value, unsigned int number);
    std::string info();
};

#endif // DB_H
