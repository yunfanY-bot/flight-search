#include "airport.h"
#include "route.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, Airport> the_map;

int main() {


    Airport tmp_a;
    vector<Airport> all_airports = tmp_a.parse_airports_from_file();

    route tmp_r;
    vector<route> all_routes = tmp_r.parse_routes_from_file();

    route Beijing_Shanghai = tmp_r.search_route("PVG", "PEK", all_routes);
    cout<<Beijing_Shanghai.get_distance()<<endl;

}



