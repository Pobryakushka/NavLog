#include "parsernmea.h"

unsigned int calculateXOR(const std::string &str)
{
    int counterXor {};
    for (int i{0}; i < static_cast<int>(str.size()); ++i)
    {
        counterXor ^=  str[i];
    }
    return counterXor;
}

bool isChecksumValid(const std::string &str)
{
    int checksum {};

}

std::vector<std::string> splitString(const std::string &str)
{

}

std::string getType(const std::vector<std::string> &array)
{

}