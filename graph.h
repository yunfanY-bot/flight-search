#pragma once

#include <list>
#include <unordered_map>
#include <utility>
#include <algorithm>

#include <iostream>
#include <iomanip>
#include <set>
#include <sstream>
#include <vector>
#include "airport.h"

#include "route.h"

using namespace std;


class Graph {
    public:
    //draw graph use helper functions in Airport and route classes
    Graph();//definitely a weighted graph
    Airport getAdjacent(Airport source) const;//get all adj vertices
    Airport getVertices() const; //gets all vertices, debug used
    route getRoutes(Airport source, Airport destination) const;//find a route between 2 airports
    void insertVertex();//insert an airport
    void removeVertex();//remove an airport
    bool insertRoutes(Airport source, Airport destination);//build route between 2 airports (seems fixed when parsing the txt?)
    route removeRoutes(Airport source, Airport destination);
    route setRoutedistance(Airport source, Airport destination, int distance);//use weight to set distance


    vector<route> findshorteset(Airport source, Airport destination);//return a combination of routes that are shortest using Dijakra's


    private:
    bool weighted; //if weighted
    bool directed;
    mutable unordered_map<Airport, unordered_map<Airport, route>> adjacency;
    bool assertVertexExists(Airport v) const; //check if exists helper func
    bool assertEdgeExists(Airport source, Airport destination) const; // check if exists helper func



   

};
