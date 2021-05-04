#include "airport.h"
#include "route.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <map>

using namespace std;


int main() {

    map<string, Airport> the_map;//maps airport id to airport object

    Airport tmp_a;
    vector<Airport> all_airports = tmp_a.parse_airports_from_file(the_map);

    route tmp_r;
    vector<route> all_routes = tmp_r.parse_routes_from_file(the_map);
}



