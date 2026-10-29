#include <iostream>
#include "pathdistance.h"
#include "point.h"
#include "parsernmea.h"

int main()
{
    std::vector<Point> track1 = {
        { 54.1931, 37.6177, 180 },   // Тула
        { 55.7558, 37.6173, 150 },   // Москва
        { 56.8587, 35.9176, 140 },   // Тверь
        { 59.9343, 30.3351,   5 },   // Петербург
        { 58.5215, 31.2755,  25 },   // Новгород
    };
    std::vector<Point> track2 = {
        { 55.7558, 37.6173, 150 },   // Москва
        { 54.1931, 37.6177, 180 },   // Тула
        { 52.9703, 36.0635, 190 },   // Орёл
        { 43.6797, 40.2049, 560 },   // Красная Поляна
    };
    std::vector<Point> track3 = {
        { 31.50, 35.50, -430 },      // Мёртвое море, точка 1
        { 31.60, 35.52, -425 },      // точка 2
        { 31.70, 35.55, -428 },      // точка 3
    };
    std::vector<Point> points = {track3};
    std::cout << pathDistance(points) << std::endl;
    std::cout << longestSegment(points) << std::endl;
    std::cout << highestPoint(points) << std::endl;

    std::vector<std::string> testSentences = {
        "$GPGGA,123519.00,5411.586,N,03737.062,E,1,08,0.9,180.4,M,14.2,M,,*64", // GGA, правильная
        "$GPRMC,123519.00,A,5411.586,N,03737.062,E,012.4,084.4,281026,,,A*5D",  // RMC, правильная
        "$GPVTG,084.4,T,,M,012.4,N,023.0,K,A*03",                               // VTG, правильная
        "$GNGGA,123520.00,,,,,0,00,99.9,,,,,,*46",                              // GGA без фиксации, сумма правильная
        "$GPGGA,123519.00,5411.586,N,03737.062,E,1,08,0.9,180.4,M,14.2,M,,*65", // неверная сумма
        "$GPGGA,123519.00,5411.586,N,03737.0",                                  // обрыв, нет *
        "GPGGA,123519.00*00",                                                   // нет $
    };

    for (int i{0}; i < static_cast<int>(testSentences.size()); ++i)
    {
    std::cout << splitString(testSentences[i]) << std::endl;
    }
}
