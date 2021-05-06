#include "graph.h"
extern map<string, Airport> the_map;
extern map<int, Airport> the_id_map;


Graph::Graph(vector<Airport> set_all_airports, vector<route> set_all_routes)
{
    all_airports.swap(set_all_airports);
    all_routes.swap(set_all_routes);
    build_graph();
}

void Graph::build_graph() {
    int count = 0;
    for (Airport each_airport : all_airports) {
        map<int, double> a;
        a.insert(pair<int, double>(each_airport.airport_id, 0));
        for (Airport each_airport2 : all_airports) {
            adjacency.insert(pair<int, map<int, double>>(each_airport2.airport_id, a));
        }
    }
    for (route each_route : all_routes) {
        if (each_route.airline == "default") {// no airport record found for this route
            continue;
        } else {
            if (adjacency[each_route.depature.airport_id][each_route.destination.airport_id] != 0) {
                continue;
            }
            adjacency[each_route.depature.airport_id][each_route.destination.airport_id] = each_route.get_distance();
        }
    }
}


vector<Airport> Graph::getAdjacent(Airport source) const 
{
    return getAdjacent(source.airport_id);
}

vector<Airport> Graph::getAdjacent(int id) const 
{
    vector<Airport> to_return;
    map<int, double> list = adjacency[id];
    for (auto iter = list.begin(); iter != list.end(); iter++) {
        if (iter->second != 0) {
            to_return.push_back(the_id_map[iter->first]);
        }
    }
    return to_return;
}

bool Graph::ifVertexExists(Airport v) const
{
    return adjacency.find(v.airport_id) != adjacency.end();
}


bool Graph::ifRouteExists(Airport source, Airport destination) const
{
    return adjacency[source.airport_id][destination.airport_id] != 0;
}

pair<int, double> Graph::d_min(map<int, double> the_map) {
    auto b = the_map.begin();
    for (auto it = the_map.begin(); it != the_map.end(); it++) {
        if (it->second < b->second) {
            b = it;
        }
    }
    return *b;
}

vector<Airport> Graph::SSP(Airport source, Airport destination) {
    vector<Airport> to_return;
    map<int, double> total_dis;
    map<int, int> predecessor;
    for (Airport each_airport : all_airports) {
        total_dis[each_airport.airport_id] = std::numeric_limits< double >::infinity(); // -1 is infinity
        predecessor[each_airport.airport_id]; //-1 is NULL airport
    }
    total_dis[source.airport_id] = 0;
    for(unsigned i = 0; i < all_airports.size(); i++) {
        pair<int, double> min = d_min(total_dis);
        total_dis.erase(min.first);
        vector<Airport> neighbors = getAdjacent(min.first);
        for (Airport each_n : neighbors) {
            if (adjacency[the_id_map[min.first].airport_id][each_n.airport_id]
                + total_dis[min.first] < total_dis[each_n.airport_id]) {
                    total_dis[each_n.airport_id] = adjacency[the_id_map[min.first].airport_id][each_n.airport_id]
                                                    + total_dis[min.first] < total_dis[each_n.airport_id];
                    predecessor[each_n.airport_id] = min.first;
                    cout<<each_n.airport_id<<endl;
                }
        }
    }
    cout<<"here"<<endl;
    int p = predecessor[destination.airport_id];
    to_return.push_back(the_id_map[p]);
    while(p != -1) {
        p = predecessor[p];
        to_return.push_back(the_id_map[p]);
    }

    /*
    foreach (Vertex v : G):
    d[v] = +inf
    p[v] = NULL 
    d[s] = 0
    PriorityQueue Q // min distance, defined by d[v] 
    Q.buildHeap(G.vertices())
    Graph T // "labeled set"
    repeat n times:
    Vertex u = Q.removeMin()
    T.add(u)
    foreach (Vertex v : neighbors of u not in T):
    if _______________ < d[v]: d[v] = __________________ p[v] = m

        return vector<route>();
        */


    /*
    for (Airport each_airport : all_airport) {
        each_airport.d = -1; //-1 is infinity
        each_airport.p = -1; //-1 is NULL airport
    }
    source.d = 0;
    PriorityQueue Q;
    */
    

    return to_return;

}