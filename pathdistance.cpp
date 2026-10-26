#include "pathdistance.h"
#include "haversinus.h"

double pathDistance(const std::vector<Point> &points)
{
    double totalKm{};
    for (int i = 0; i + 1 < static_cast<int>(points.size()); ++i)
    {
        totalKm += haversinusDistance(points[i], points[i+1]);
    }
    return totalKm;
}
