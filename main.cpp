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

int main() {

    cout<<"Parsing data..."<<endl;
    //create airport instance
    Airport tmp_a;
    //start parsing file
    vector<Airport> all_airports = tmp_a.parse_airports_from_file();

    route tmp_r;
    vector<route> all_routes = tmp_r.parse_routes_from_file();
    
    cout<<"Building Graph, may take several minutes..."<<endl;
    Graph a = Graph(all_airports, all_routes);

    string dep;
    string des;

    while (1) {

        cout<<"Please type depature airport IATA code (input q to quit):"<<endl;
        cin>>dep;
        //if user pressed  q, quit the program
        if (dep == "q") {
            return 1;
        }
        cout<<"Please type destination airport IATA code (input q to quit):"<<endl;
        cin>>des;
        if (des == "q") {
            return 1;
        }

        //if no mapping found, this airport does not exist
        if (the_map[dep].airport_id == 0 || the_map[des].airport_id == 0) {
            cout<<"No such airport!"<<endl;
            return 1;
        }

        cout<<"Searching for route..."<<endl;

        //search for shortest path
        vector<Airport> result = a.SSP(the_map[dep], the_map[des]);

        cout<<""<<endl;

        cout<<">>>>>>>>>>>>>>Result<<<<<<<<<<<<<<"<<endl;

        long double total_d = 0;

        for (int i = result.size() - 1; i >= 0; i--) {
            long double cur_d = 0;
            if (i == 0) {
                //calculate intermediate route distance
                cur_d = tmp_r.search_route(result[i].iata, des, all_routes).get_distance();
            } else {
                //calculate the final jump distance
                cur_d = tmp_r.search_route(result[i].iata, result[i-1].iata, all_routes).get_distance();
            }
            // total distance
            total_d += cur_d;
            //some print formatting
            result[i].print_airport();
            cout<<"      |"<<endl;
            cout<<"      |"<<endl;
            cout<<"      | "<<cur_d<<" KM"<<endl;
            cout<<"      |"<<endl;
            cout<<"      |"<<endl;
        }
        the_map[des].print_airport();
        
        cout<<""<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"Total Distance is:  "<<endl;
        cout<<total_d<<" KM "<<endl;
        cout<<""<<endl;
        cout<<""<<endl;
    }
}



