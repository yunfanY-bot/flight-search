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


    //warning: do NOT use operator < . Only used for minheap and map;
    bool operator>(const Airport& other) const;
    //WARNING!! DO NOT use d and p; 



    void print_airport();

    //parse form file
    vector<Airport> parse_airports_from_file();

    //helper function to split string
    void split(const string & s, string c, vector<string> & v);

    void set_d(double);
    void set_p(int);
    double get_d() const;
    int get_p() const;

    private:
    //warning: do NOT use following fields. Only used for minheap;
    double d; //cumulative distance used in SSP
    int p; //predecessor airport id
    //WARNING!! DO NOT use d and p;



};
