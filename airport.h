#progma once
#include <string>
#include <iostream>

class airport {
public:
    int airport_id;
    string name;
    string country;
    string city;
    string iata; //iata code
    string icao; //icao code
    double longitude;
    double latitude;

    void print_airport();

}