#include "coordinate.h"
#include <string>
#include <iostream>

using namespace std;

/**
 * @brief default constructor
 */
Coordinate::Coordinate() {
    lat = 0.0;
    lon = 0.0;
}

/**
 * @brief constructor
 * 
 * @param set_lat // set lattitude
 * @param set_lon // set longitude
 */
Coordinate::Coordinate(long double set_lat, long double set_lon) {
        lat = set_lat;
        lon = set_lon;
}

/**
 * @brief helper func to convert angle
 * @param degree // degree to be converted
 * @return //angle in rarius
 */
long double Coordinate::toRad(long double degree) {
        return degree/180 * M_PI;
}

/**
 * @brief helper func to calculate distance of two points
 * @param other // the other coordinate
 */
long double Coordinate::calculateDistance(Coordinate other) {
        long double dist;
        dist = sin(toRad(lat)) * sin(toRad(other.lat)) 
            + cos(toRad(lat)) * cos(toRad(other.lat)) * cos(toRad(lon - other.lon));
        dist = acos(dist);
        //dist = (6371 * pi * dist) / 180;
        //got dist in radian, no need to change back to degree and convert to rad again.
        dist = 6371 * dist;
        return dist;
}

/**
 * @brief helper func to print
 */
void Coordinate::print_cor() {
        cout<<"Lat: "<<lat<<endl;
        cout<<"Lon: "<<lon<<endl;
}