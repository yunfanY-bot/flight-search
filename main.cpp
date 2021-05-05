#include "airport.h"
#include "route.h"
#include "graph.h"
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
    Beijing_Shanghai.print_route();

    route pvg_sfo = tmp_r.search_route("PVG", "SFO", all_routes);
    pvg_sfo.print_route();

}



