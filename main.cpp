#include <iomanip>
#include <iostream>
#include <optional>
#include <string>
#include <vector>
#include "pathdistance.h"
#include "point.h"
#include "parsernmea.h"

void testDistance()
{
    const std::vector<std::vector<Point>> tracks{
        {
            { .latitude = 54.1931, .longitude = 37.6177, .height = 180 },  // Тула
            { .latitude = 55.7558, .longitude = 37.6173, .height = 150 },  // Москва
            { .latitude = 56.8587, .longitude = 35.9176, .height = 140 },  // Тверь
            { .latitude = 59.9343, .longitude = 30.3351, .height = 5 },    // Петербург
            { .latitude = 58.5215, .longitude = 31.2755, .height = 25 },   // Новгород
        },
        {
            { .latitude = 55.7558, .longitude = 37.6173, .height = 150 },  // Москва
            { .latitude = 54.1931, .longitude = 37.6177, .height = 180 },  // Тула
            { .latitude = 52.9703, .longitude = 36.0635, .height = 190 },  // Орёл
            { .latitude = 43.6797, .longitude = 40.2049, .height = 560 },  // Красная Поляна
        },
        {
            { .latitude = 31.50, .longitude = 35.50, .height = -430 },     // Мёртвое море
            { .latitude = 31.60, .longitude = 35.52, .height = -425 },
            { .latitude = 31.70, .longitude = 35.55, .height = -428 },
        },
    };

    for (const auto& track : tracks)
    {
        std::cout << "path " << pathDistance(track)
                  << "  longest " << longestSegment(track)
                  << "  highest " << highestPoint(track) << '\n';
    }
    std::cout << '\n';
}

void printPoint(const std::optional<Point>& point)
{
    if (!point)
    {
        std::cout << "  no position\n";
        return;
    }
    std::cout << std::fixed << std::setprecision(4)
              << "  time " << point->time
              << "  lat " << point->latitude
              << "  lon " << point->longitude
              << "  height " << point->height
              << "  sat " << point->satellites << '\n';
    std::cout.unsetf(std::ios::fixed);   // вернуть обычный формат вывода
}

void testParsing()
{
    const std::vector<std::string> testSentences{
        // GGA
        "$GPGGA,123519.00,5411.586,N,03737.062,E,1,08,0.9,180.4,M,14.2,M,,*64", // 54.1931 37.6177 180.4 8
        "$GPGGA,081500.00,3352.128,S,15112.558,E,1,10,0.8,25.0,M,22.0,M,,*41",  // -33.8688 151.2093 25.0 10
        "$GNGGA,123520.00,,,,,0,00,99.9,,,,,,*46",                              // no position
        // RMC
        "$GPRMC,123519.00,A,5411.586,N,03737.062,E,012.4,084.4,281026,,,A*5D",  // 54.1931 37.6177
        "$GPRMC,153000.00,A,4042.768,N,07400.360,W,000.5,054.7,051126,,,A*44",  // 40.7128 -74.0060
        "$GPRMC,123520.00,V,,,,,,,281026,,,N*75",                               // no position
        // тип, который не разбираем
        "$GPVTG,084.4,T,,M,012.4,N,023.0,K,A*03",                               // unsupported type: VTG
        // битые
        "$GPGGA,123519.00,5411.586,N,03737.062,E,1,08,0.9,180.4,M,14.2,M,,*65", // bad checksum
        "$GPGGA,123519.00,5411.586,N,03737.0",                                  // bad checksum (нет *)
        "GPGGA,123519.00*00",                                                   // bad checksum (нет $)
    };

    for (const auto& sentence : testSentences)
    {
        std::cout << sentence << '\n';

        if (!isChecksumValid(sentence))
        {
            std::cout << "  bad checksum\n";
            continue;
        }

        const std::vector<std::string> fields = splitString(sentence);
        const std::string type = getType(fields);

        if (type == "GGA")
        {
            printPoint(parseGGA(fields));
        }
        else if (type == "RMC")
        {
            printPoint(parseRMC(fields));
        }
        else if (type.empty())
        {
            std::cout << "  can't get type\n";
        }
        else
        {
            std::cout << "  unsupported type: " << type << '\n';
        }
    }

    // крайние случаи getType
    std::cout << "getType({\"GP\"}) empty: " << getType({"GP"}).empty() << '\n';
    std::cout << "getType({}) empty: " << getType({}).empty() << '\n';
}

int main()
{
    testDistance();
    testParsing();
    return 0;
}
