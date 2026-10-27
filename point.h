#ifndef POINT_H
#define POINT_H

#include <string>
#include <vector>

struct Point
{
    double latitude{};
    double longitude{};
    double height{};
    std::string time;
};

double highestPoint(const std::vector<Point> &points);

#endif // POINT_H
