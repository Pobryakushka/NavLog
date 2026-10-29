#ifndef PARSERNMEA_H
#define PARSERNMEA_H

#include <string>
#include <vector>

bool checksumXOR(const std::string &str);
std::vector<std::string> splitString(const std::string &str);
std::string getType(const std::vector<std::string> &array);

// std::string checkumXOR(const std::string str);

#endif // PARSERNMEA_H
