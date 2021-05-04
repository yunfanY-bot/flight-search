#pragma once
#include <string>
#include <iostream>
#include <math.h>

using namespace std;
class Coordinate {
public:
    double lat;
    double lon;
    Coordinate();
    Coordinate(double set_lat, double set_lon);
    double toRad(double degree);
    double calculateDistance(double lat1, double long1, double lat2, double long2);
    double calculateDistance(Coordinate other);
    void print_cor();
};