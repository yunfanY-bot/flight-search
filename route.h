#pragma once
#include "airport.h"
#include <string>
#include <fstream>
#include <iostream>
#include "coordinate.h"
#include <vector>


class route {
public:
    route();
    route(string set_airline, string set_airline_ID, string set_departure_id, string set_destionation_ID);
    long double get_distance();
    vector<route> parse_routes_from_file();
    route search_route(string, string, vector<route>);
    void print_route();
    
    string airline;
    string airline_id;
    Airport depature;
    string depature_id;
    Airport destination;
    string destination_id;
    bool is_air;
    long double distance;

    
private:

    void set_airports_distance();

    //return the distance of the route

    //helper function to split string
    void split(const string & s, string c, vector<string> & v);
};
