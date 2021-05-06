#include "route.h"
#include "airport.h"
#include <iostream>
#include <map>

extern map<string, Airport> the_map;
extern map<int, Airport> the_id_map;


route::route() {
    airline = "default";
    airline_id = "0";
    depature = Airport(); 
    depature_id = "default"; 
    destination = Airport(); 
    destination_id = "default"; 
    is_air = true; // default mode
    distance = -1; //uninitialized distance
}

route::route(string set_airline, string set_airline_ID, string set_departure_id
                , string set_destionation_ID) {
    airline = set_airline;
    airline_id = set_airline_ID;
    depature_id = set_departure_id; 
    destination_id = set_destionation_ID; 
    is_air = true; // default mode
    distance = -1; //uinirtialized distance
    
}

void route::set_airports_distance() {
    depature = the_map[depature_id];
    destination = the_map[destination_id];
    if (depature.iata == "default" || destination.iata == "default" ) {
        airline = "default";
        airline_id = "0";
        distance = -1; //uninitialized distance
    } else {
        distance = depature.cor.calculateDistance(destination.cor);
    }

    
}

//print all variables of a route
void route::print_route() {
    cout<<"depature_id: "<<depature_id<<endl;
    cout<<"destination_id: "<<destination_id<<endl;
    cout<<"airline: "<<airline<<endl;
    cout<<"airline_id: "<<airline_id<<endl;
    cout<<"distance: "<<distance<<endl;

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

vector<route> route::parse_routes_from_file() {
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
            route cur = route(v[0], v[1], v[2], v[4]);
            cur.set_airports_distance();
            all_routes.push_back(cur);
        } catch (const std::exception& e) {
            cout<<e.what()<<endl;
        }
    }
    file.close();
    return all_routes;
}


/**
 * @brief search for a route. it not found, return default route
 * 
 * @param depa // the depature iata code 
 * @param name // the destination iata code
 * @param all_routes // an array containing all the routes
 * @return  // the route object
 * 
 */
route route::search_route(string depa, string dest, vector<route> all_routes) {
    vector<route> tmp;
    for(route route1 : all_routes) {
        if (route1.depature_id == depa) {
            tmp.push_back(route1);
        }
    }   
    for(route route1 : tmp) {
        if (route1.destination_id == dest) {
            return route1;
        }
    }    
    return route();
}


