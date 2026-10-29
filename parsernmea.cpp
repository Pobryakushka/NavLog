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

//  $GPGGA,123519.00,5411.586,N,03737.062,E,1,08,0.9,180.4,M,14.2,M,,*64

std::vector<std::string> splitString(const std::string &str)
{
    std::vector<std::string> fieldsArray = {};

    for (int i{0}; i < static_cast<int>(str.size()); ++i)
    {
        int delimiterPos1 = str.find(',');
        int delimiterPos2 = str.find(',', delimiterPos1 + 1);
        fieldsArray.push_back(str.substr(delimiterPos1 + 1, delimiterPos2 - delimiterPos1));
    }
    return fieldsArray;
}

std::string getType(const std::vector<std::string> &array)
{

}