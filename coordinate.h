#pragma once
#include <string>
#include <iostream>
#include <math.h>

using namespace std;
class Coordinate {
public:
    long double lat;
    long double lon;
    //default constructor
    Coordinate();
    // constructor
    Coordinate(long double set_lat, long double set_lon);
    //helper func to convert angle
    long double toRad(long double degree);
    //helper func to calculate distance of two points
    long double calculateDistance(Coordinate other);
    //print
    void print_cor();
};