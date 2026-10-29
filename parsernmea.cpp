#include "parsernmea.h"

static unsigned int calculateXOR(const std::string &str)
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
    size_t startPos = str.find('$');
    if (startPos != 0)
        return false;

    size_t endPos = str.find('*');
    if (endPos == std::string::npos)
        return false;

    if (str.length() - (endPos + 1) != 2)
        return false;

    int checksum = calculateXOR(str.substr(startPos + 1, endPos - (startPos + 1)));

    std::string hexStr = str.substr(endPos +1, 2);

    int checksumCheck = std::stoi(hexStr, nullptr, 16);

    return (checksumCheck == checksum);
}

std::vector<std::string> splitString(const std::string &str)
{

}

std::string getType(const std::vector<std::string> &array)
{

}