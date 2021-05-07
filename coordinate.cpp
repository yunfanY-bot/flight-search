#include "coordinate.h"
#include <string>
#include <iostream>

using namespace std;

Coordinate::Coordinate() {
    lat = 0.0;
    lon = 0.0;
}

Coordinate::Coordinate(long double set_lat, long double set_lon) {
        lat = set_lat;
        lon = set_lon;
}

long double Coordinate::toRad(long double degree) {
        return degree/180 * M_PI;
}

long double Coordinate::calculateDistance(long double lat1, long double long1, long double lat2, long double long2) {
        long double dist;
        dist = sin(toRad(lat1)) * sin(toRad(lat2)) + cos(toRad(lat1)) * cos(toRad(lat2)) * cos(toRad(long1 - long2));
        dist = acos(dist);
        //dist = (6371 * pi * dist) / 180;
        //got dist in radian, no need to change back to degree and convert to rad again.
        dist = 6371 * dist;
        return dist;
}

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

void Coordinate::print_cor() {
        cout<<"Lat: "<<lat<<endl;
        cout<<"Lon: "<<lon<<endl;
}