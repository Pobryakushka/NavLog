#include "haversinus.h"
#include <cmath>
#include <numbers>

static constexpr double earthAvgRadius = 6371; // км
static constexpr double pi = std::numbers::pi;

static double degreesToRad(double degrees)
{
    double radians = degrees * pi/180;
    return radians;
}

double haversinusDistance(const Point &p1, const Point &p2)
{
    double latitudeDiff = degreesToRad(p2.latitude) - degreesToRad(p1.latitude);
    double longitudeDiff = degreesToRad(p2.longitude) - degreesToRad(p1.longitude);
    double a = std::pow(std::sin(latitudeDiff/2), 2) + std::cos(degreesToRad(p1.latitude)) * std::cos(degreesToRad(p2.latitude)) * std::pow(std::sin(longitudeDiff/2), 2);
    double centralAngle = 2 * std::asin(std::sqrt(a));
    double distanceKm = earthAvgRadius * centralAngle;
    return distanceKm;
}

