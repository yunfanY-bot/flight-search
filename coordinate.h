#pragma once
#include <string>
#include <iostream>
#include <math.h>

using namespace std;
class Coordinate {
public:
    long double lat;
    long double lon;
    Coordinate();
    Coordinate(long double set_lat, long double set_lon);
    long double toRad(long double degree);
    long double calculateDistance(long double lat1, long double long1, long double lat2, long double long2);
    long double calculateDistance(Coordinate other);
    void print_cor();
};