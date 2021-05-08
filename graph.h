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
    
    vector<Airport> getAdjacent(Airport source) const;//get all adj vertices
    Airport getVertices() const; //gets all vertices, debug used
    route getRoutes(Airport source, Airport destination) const;//find a route between 2 airports
    void insertVertex(Airport a);//insert an airport
    Airport removeVertex(Airport v);
    bool insertRoutes(route r);//build route between 2 airports (seems fixed when parsing the txt?)
    route removeRoutes(Airport source, Airport destination);
    route setRoutedistance(Airport source, Airport destination, int distance);//use weight to set distance
    vector<Airport> SSP(Airport source, Airport destination);//return a combination of routes that are shortest using Dijakra's 
    bool ifVertexExists(Airport v) const; //check if exists helper func
    bool ifRouteExists(Airport source, Airport destination) const; // check if exists helper func 如果没有才能insert
    mutable map<int, map<int, long double>> adjacency;
    vector<Airport> getAdjacent(int id) const;
    pair<int, long double> d_min(map<int, long double> the_map);
    private:
    vector<Airport> all_airports;
    vector<route> all_routes;
    void build_graph();
    
    
    
    
};