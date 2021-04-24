#pragma once
#include <string>
#include <iostream>

class airport {
public:
    int airport_id;
    std::string name;
    std::string country;
    std::string city;
    std::string iata; //iata code
    std::string icao; //icao code
    double longitude;
    double latitude;
    
    Airport();
    Airport(std::string name, std::string city, double lat, double lon, std::string id);
    
    void print_airport();

};
