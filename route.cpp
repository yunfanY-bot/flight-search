#include "route.h"
#include "airport.h"
#include <iostream>
#include <map>

route::route() {
    airline = "default";
    airline_id = 0;
    depature = Airport(); 
    depature_id = "default"; 
    destination = Airport(); 
    destination_id = "default"; 
    is_air = true; // default mode
    distance = -1; //uinirtialized distance
}

route::route(string set_airline, int set_airline_ID, string set_departure_id
                , string set_destionation_ID) {
    airline = set_airline;
    airline_id = set_airline_ID;
    depature_id = set_departure_id; 
    destination_id = set_destionation_ID; 
    is_air = true; // default mode
    distance = -1; //uinirtialized distance
    
}

void route::set_airports_distance(map<string, Airport> the_map) {
    depature = the_map[depature_id];
    destination = the_map[destination_id];
}

//print all variables of a route
void route::print_route() {
    cout<<"depature_id"<<depature_id<<endl;
    cout<<"destination_id"<<destination_id<<endl;
}

//calculate route distance
double route::get_distance() {
    return distance;
}

void route::split(const string & s, string c, vector<string> & v) {
    int i = 0;
    int j=s.find(c);
    if (s == "") return;
    while(j > 0 ) {
        v.push_back(s.substr(i, j-i));
        i = ++j;
        j = s.find(c, j);
    }
}

vector<route> route::parse_routes_from_file(map<string, Airport> the_map) {
    ifstream file;
    file.open("routes.dat.txt");
    string line;
    vector<route> all_routes;
    while (getline(file, line)) {
        vector<string> v;
        if (line == "") {
            break;
        }
        split(line, ",", v);
        try{
            route cur = route(v[0], stod(v[1]), v[2], v[4]);
            cur.set_airports_distance(the_map);
            all_routes.push_back(cur);
        } catch (const std::exception& e) {
            cout<<e.what()<<endl;
        }
    }
    file.close();
    return all_routes;
}


