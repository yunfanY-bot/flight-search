#pragma once
#include "airport.h"
#include <string>
#include <fstream>
#include <iostream>
#include "coordinate.h"
#include <vector>


class route {
public:
    //default constructor
    route();
    //constructor
    route(string set_airline, string set_airline_ID, string set_departure_id, string set_destionation_ID);
    long double get_distance();
    //parse data
    vector<route> parse_routes_from_file();
    //search a route
    route search_route(string, string, vector<route>);
    //print
    void print_route();
    
    string airline;
    string airline_id;
    Airport depature;
    //depature airport iata code
    string depature_id;
    Airport destination;
    //destination airport iata code
    string destination_id;
    //route distance
    long double distance;

    
private:
    void set_airports_distance();
    //helper function to split string
    void split(const string & s, string c, vector<string> & v);
};
