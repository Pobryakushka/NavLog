#include "point.h"

double highestPoint(const std::vector<Point> &points)
{
    double maxHeight = points[0].height;
    for (int i = 0; i < static_cast<int>(points.size()); ++i)
    {
        if (maxHeight < points[i].height)
            maxHeight = points[i].height;
    }
    return maxHeight;
}