#include "graph.h"
extern map<string, Airport> the_map;
extern map<int, Airport> the_id_map;

/**
 * @brief constructor
 * @param set_all_airports // vector of all airports
 * @param set_all_routes // vector of all routes
 */
Graph::Graph(vector<Airport> set_all_airports, vector<route> set_all_routes)
{
    all_airports.swap(set_all_airports);
    all_routes.swap(set_all_routes);
    build_graph();
}

/**
 * @brief //build graph, once and for all
 * @param set_all_airports // vector of all airports
 * @param set_all_routes // vector of all routes
 */
void Graph::build_graph() {
    int count = 0;
    for (Airport each_airport : all_airports) {
        // build the adjacency matrix
        map<int, long double> a;
        a.insert(pair<int, long double>(each_airport.airport_id, 0));
        for (Airport each_airport2 : all_airports) {
            adjacency.insert(pair<int, map<int, long double>>(each_airport2.airport_id, a));
        }
    }
    for (route each_route : all_routes) {
        if (each_route.airline == "default") {
            // no airport record found for this route
            continue;
        } else {
            //since multiple airlines for the same route exist
            //we don't do repeated work
            if (adjacency[each_route.depature.airport_id][each_route.destination.airport_id] != 0) {
                continue;
            }
            //store distance in adjacency matrix
            adjacency[each_route.depature.airport_id][each_route.destination.airport_id] = each_route.get_distance();
        }
    }
}

/**
 * @brief get adjacent airports
 * @param source // source airports
 * @return neighbour airports
 */
vector<Airport> Graph::getAdjacent(Airport source) const 
{
    return getAdjacent(source.airport_id);
}

/**
 * @brief get adjacent airports
 * @param id // source airport's id
 * @return neighbour airports
 */
vector<Airport> Graph::getAdjacent(int id) const 
{
    vector<Airport> to_return;
    map<int, long double> list = adjacency[id];
    for (auto iter = list.begin(); iter != list.end(); iter++) {
        if (iter->second != 0) {
            //if the route distance is not zero, then the route exists
            to_return.push_back(the_id_map[iter->first]);
        }
    }
    return to_return;
}

/**
 * @brief find the minimum value in a map
 * @param the_map // the map to be inserted
 * @return a pair object of the minimum pair
 */
pair<int, long double> Graph::d_min(map<int, long double> the_map) {
    auto b = the_map.begin();
    for (auto it = the_map.begin(); it != the_map.end(); it++) {
        if (it->second < b->second) {
            b = it;
        }
    }
    return *b;
}

/**
 * @brief search for the shortest path given a source and a destination airport
 * @param source // source airport
 * @param source // destination
 * @return a vector of all airports included in the shortest path
 */
vector<Airport> Graph::SSP(Airport source, Airport destination) {
    vector<Airport> to_return;
    //record the current total distance of the current node
    map<int, long double> total_dis;
    //record the predecessor of the current node
    map<int, int> predecessor;
    //visited node
    vector<int> visited;
    //source is visited
    visited.push_back(source.airport_id);
    for (Airport each_airport : all_airports) {
        //initialize total distance and predecessor
        total_dis[each_airport.airport_id] = std::numeric_limits< long double >::infinity(); // -1 is infinity
        predecessor[each_airport.airport_id] = -1; //-1 is NULL airport
    }
    total_dis[source.airport_id] = 0;
    for(unsigned i = 0; i < all_airports.size(); i++) {
        pair<int, long double> min = d_min(total_dis);
        int min_id = min.first;
        long double cur_dis = min.second;
        total_dis.erase(min.first);
        //set as visited
        visited.push_back(min_id);
        //get adjacent nodes
        vector<Airport> neighbors = getAdjacent(min_id);
        for (Airport each_n : neighbors) {
            bool trigger = false;
            for (int a : visited) {
                if (a == each_n.airport_id) {
                    //if visited, set trigger
                    trigger = true;
                }
            }
            if (trigger) {
                //ignore this node if visited
                continue;
            }
            if (adjacency[min_id][each_n.airport_id]
                + cur_dis < total_dis[each_n.airport_id]) {
                    //update shortest total distance of current node
                    total_dis[each_n.airport_id] = adjacency[min_id][each_n.airport_id]
                                                    + cur_dis;
                    predecessor[each_n.airport_id] = min_id;
                }
        }
    }
    int p = predecessor[destination.airport_id];
    to_return.push_back(the_id_map[p]);
    //until the source airport is reached, trace back and add visited airport to the path
    while(predecessor[p] != -1) {
        p = predecessor[p];
        to_return.push_back(the_id_map[p]);
    }
    return to_return;
}