#pragma once

#include <utility>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <climits>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <set>
#include <sstream>
#include <vector>
#include "airport.h"
#include <map>
#include <unordered_map>
#include "route.h"

using namespace std;


class Graph {
    public:
    //draw graph use helper functions in Airport and route classes
    Graph(vector<Airport> set_all_airports, vector<route> set_all_routes);
    //get adjacent airports
    vector<Airport> getAdjacent(Airport source) const;//get all adj vertices
    //search for the shortest path given a source and a destination airport Dijakra algorithm
    vector<Airport> SSP(Airport source, Airport destination);

    private:
    //the adjacency matrix
    //instead of <airport, map<airport, route>> to store objects directly
    //we use <int, map<int, long double>> to store airport id and rourte distance
    //and use a map to link link id to airport objects
    //because this improves performance a lot
    mutable map<int, map<int, long double>> adjacency;
    //all airports and routes
    vector<Airport> all_airports;
    vector<route> all_routes;    
    //get adjacent airports
    vector<Airport> getAdjacent(int id) const;
    //find minimum
    pair<int, long double> d_min(map<int, long double> the_map);
    //build graph, once and for all
    void build_graph();
    
    
    
    
};
