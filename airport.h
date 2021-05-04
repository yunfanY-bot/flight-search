#pragma once
#include <string>
#include <iostream>
#include "coordinate.h"

using namespace std;

class Airport {
public:
    int airport_id;
    string name;
    string country;
    string city;
    string iata; //iata code
    string icao; //icao code
    Coordinate cor;
    
    Airport();
    Airport(int id, string name, string city
            , string country, string iata
            , string icao, double lat, double lon);
    
    void print_airport();

};
