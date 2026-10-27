#include <iostream>
#include "pathdistance.h"
#include "point.h"

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
}
