#include "point.h"
#include <algorithm>
#include <vector>

double highestPoint(const std::vector<Point> &points)
{
    double maxHeight = points[0].height;
    for (int i = 0; i < static_cast<int>(points.size()); ++i)
    {
        maxHeight = std::max(maxHeight, points[i].height);
    }
    return maxHeight;
}
