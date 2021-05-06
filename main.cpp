#include "airport.h"
#include "route.h"
#include "graph.h"
#include <fstream>
#include <vector>
#include <queue>
#include <iostream>
#include <string>
#include <map>
#include <unordered_map>

using namespace std;

map<string, Airport> the_map;
map<int, Airport> the_id_map;


struct CompareAirport {
    bool operator()(Airport const& p1, Airport const& p2) const
    {
        if (p1.get_d() == -1 && p2.get_d() == -1) {
            return false;
        } else if (p1.get_d() == -1 && p2.get_d() != -1) {
            return true;
        } else if (p1.get_d() != -1 && p2.get_d() == -1) {
            return false;
        } else {
            return p1.get_d() > p2.get_d();
        }
    }
};


int main() {


    Airport tmp_a;
    vector<Airport> all_airports = tmp_a.parse_airports_from_file();

    route tmp_r;
    vector<route> all_routes = tmp_r.parse_routes_from_file();

    
    int count = 0;
    priority_queue<Airport, vector<Airport>, CompareAirport> q;
    
    for (Airport each : all_airports) {
        each.set_d(-1 * count);
        count++;
        q.push(each);
        if (count == 50) {
            break;
        }
    }
    
    cout<<q.top().get_d()<<endl;
    q.pop();
    q.pop();
    cout<<q.top().get_d()<<endl;
    


    /*
    for (route each : all_routes) {
        each.print_route();
    }
    */
   /*

    Graph a = Graph(all_airports, all_routes);
    int num = 3378;
    vector<Airport> neighbours = a.getAdjacent(num);
    cout<<neighbours.size()<<endl;
    */
}



