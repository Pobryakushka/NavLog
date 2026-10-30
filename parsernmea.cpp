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

// возвращает массив с разделенной NMEA строкой
// пустые поля также записываются в массив
// в первом элементе тип строки без символа $
// последний элемент содержит контрольную сумму с *
// вызывается после проверки суммы
std::vector<std::string> splitString(const std::string &str)
{
    std::vector<std::string> fieldsArray = {};
    
    size_t delimiterPos1 {0}, delimiterPos2 {0};
    
    while (delimiterPos2 != std::string::npos)
    {
        delimiterPos2 = str.find(',', delimiterPos1 + 1);
        fieldsArray.push_back(str.substr(delimiterPos1 + 1, delimiterPos2 - delimiterPos1 - 1));
        delimiterPos1 = delimiterPos2;
    }
    return fieldsArray;
}

// возвращает строку с типом NMEA строки
std::string getType(const std::vector<std::string> &array)
{
    std::string type;
    if (!array.empty() && array[0].size() >= 3){
        type = array[0].substr(array[0].size() - 3, 3);
    } else
    type = "";
    return type;
}