#pragma once
#include <string>
#include <iostream>
#include <map>
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

    Airport(const Airport& other);
    void copy(const Airport& other);
    Airport& operator=(const Airport& other);
    
    void print_airport();

    //parse form file
    vector<Airport> parse_airports_from_file();

    //helper function to split string
    void split(const string & s, string c, vector<string> & v);

};
