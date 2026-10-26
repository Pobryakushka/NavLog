#include <iostream>
#include "pathdistance.h"

int main()
{
    Point p1 = { 55.7558, 37.6173 };
    Point p2 = { 59.9343, 30.3351 };
    Point p3 = { 54.1931, 37.6177};
    std::vector<Point> points = {p1, p2, p3};
    std::cout << pathDistance(points) << std::endl;
}
