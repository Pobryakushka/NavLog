#ifndef PARSERNMEA_H
#define PARSERNMEA_H

#include "point.h"
#include <optional>
#include <string>
#include <vector>

bool isChecksumValid(const std::string &str);
std::vector<std::string> splitString(const std::string &str);
std::string getType(const std::vector<std::string> &array);

// Функция парсинга типа GGA
// Принимает в себя разобранную строку в виде вектора
// Возвращает пустоту если поля пустые
// Заполняет все поля Point и возвращает его в коллер
// В возвращаемой точке лежат все поля
std::optional<Point> parseGGA(const std::vector<std::string>& fields);

// Функция парсинга типа RMC
// Принимает в себя разобранную строку в виде вектора
// Возвращает пустоту если поля пустые
// В случае если поле ACTIVE (A) то выполняем тело функции
// В возвращаемой точке лежат все поля, кроме высоты и спутников
std::optional<Point> parseRMC(const std::vector<std::string>& fields);

// std::string checkumXOR(const std::string str);

#endif // PARSERNMEA_H
