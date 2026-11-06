#include <iostream>
#include <string>
#include <vector>
#include "pathdistance.h"
#include "point.h"
#include "parsernmea.h"

int main()
{
    std::vector<Point> track1 = {
        { .latitude=54.1931, .longitude=37.6177, .height=180 },   // Тула
        { .latitude=55.7558, .longitude=37.6173, .height=150 },   // Москва
        { .latitude=56.8587, .longitude=35.9176, .height=140 },   // Тверь
        { .latitude=59.9343, .longitude=30.3351,   .height=5 },   // Петербург
        { .latitude=58.5215, .longitude=31.2755,  .height=25 },   // Новгород
    };
    std::vector<Point> track2 = {
        { .latitude=55.7558, .longitude=37.6173, .height=150 },   // Москва
        { .latitude=54.1931, .longitude=37.6177, .height=180 },   // Тула
        { .latitude=52.9703, .longitude=36.0635, .height=190 },   // Орёл
        { .latitude=43.6797, .longitude=40.2049, .height=560 },   // Красная Поляна
    };
    std::vector<Point> track3 = {
        { .latitude=31.50, .longitude=35.50, .height=-430 },      // Мёртвое море, точка 1
        { .latitude=31.60, .longitude=35.52, .height=-425 },      // точка 2
        { .latitude=31.70, .longitude=35.55, .height=-428 },      // точка 3
    };
    const std::vector<Point>& points = {track3};
    std::cout << pathDistance(points) << '\n';
    std::cout << longestSegment(points) << '\n';
    std::cout << highestPoint(points) << '\n';

    std::vector<std::string> testSentences = {
        "$GPGGA,123519.00,5411.586,N,03737.062,E,1,08,0.9,180.4,M,14.2,M,,*64", // GGA, правильная
        "$GPRMC,123519.00,A,5411.586,N,03737.062,E,012.4,084.4,281026,,,A*5D",  // RMC, правильная
        "$GPVTG,084.4,T,,M,012.4,N,023.0,K,A*03",                               // VTG, правильная
        "$GNGGA,123520.00,,,,,0,00,99.9,,,,,,*46",                              // GGA без фиксации, сумма правильная
        "$GPGGA,123519.00,5411.586,N,03737.062,E,1,08,0.9,180.4,M,14.2,M,,*65", // неверная сумма
        "$GPGGA,123519.00,5411.586,N,03737.0",                                  // обрыв, нет *
        "GPGGA,123519.00*00",                                                   // нет $
    };


    // Цикл по всем строкам в векторе
    for (const auto& sentence : testSentences) {
        std::cout << "Processing: " << sentence << "\nResult: ";

        if (!isChecksumValid(sentence)) {
            std::cout << "Wrong checksum.\n\n";
            continue;
        }

        std::vector<std::string> stringArray = splitString(sentence);
        std::string type = getType(stringArray);

        if (type.empty()) {
            std::cout << "Can't get type of this string.\n\n";
        } else {
            std::cout << "Success! Type is: " << type << "\n\n";
        }
    }

std::vector<std::string> shortHeader = {"GP"};   // заголовок короче 3 символов
std::vector<std::string> noFields = {};          // пустой вектор

    std::cout << getType(shortHeader);
    std::cout << getType(noFields);

    return 0;
}
