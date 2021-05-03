#pragma once
#include <string>
#include <iostream>
#include "coordinate.h"


using namespace std;
class Airport {
public:
    int airport_id;
    std::string name;
    std::string country;
    std::string city;
    std::string iata; //iata code
    std::string icao; //icao code
    Coordinate cor;
    
    Airport();
    Airport(int id, std::string name,std::string city
            , std::string country, string iata
            , string icao, double lat, double lon);
    
    void print_airport();

};
