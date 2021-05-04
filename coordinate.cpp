#include "coordinate.h"
#include <string>
#include <iostream>

using namespace std;

Coordinate::Coordinate() {
    lat = 0.0;
    lon = 0.0;
}

Coordinate::Coordinate(double set_lat, double set_lon) {
        lat = set_lat;
        lon = set_lon;
}

double Coordinate::toRad(double degree) {
        return degree/180 * M_PI;
}

double Coordinate::calculateDistance(double lat1, double long1, double lat2, double long2) {
        double dist;
        dist = sin(toRad(lat1)) * sin(toRad(lat2)) + cos(toRad(lat1)) * cos(toRad(lat2)) * cos(toRad(long1 - long2));
        dist = acos(dist);
        //dist = (6371 * pi * dist) / 180;
        //got dist in radian, no need to change back to degree and convert to rad again.
        dist = 6371 * dist;
        return dist;
}

double Coordinate::calculateDistance(Coordinate other) {
        double dist;
        dist = sin(toRad(lat)) * sin(toRad(other.lat)) 
            + cos(toRad(lat)) * cos(toRad(other.lat)) * cos(toRad(lon - other.lon));
        dist = acos(dist);
        //dist = (6371 * pi * dist) / 180;
        //got dist in radian, no need to change back to degree and convert to rad again.
        dist = 6371 * dist;
        return dist;
}