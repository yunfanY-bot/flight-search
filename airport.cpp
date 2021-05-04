#include "airport.h"
#include <string>
#include <fstream>
#include <iostream>
#include <map>
#include "coordinate.h"
#include <vector>

using namespace std;

void Airport::print_airport() {//print out all the variables of airports
    cout<<"ID: " <<airport_id<<endl;
    cout<<"name: " <<name<<endl;
    cout<<"country: " <<country<<endl;    
    cout<<"City: "<<city<<endl;
    cout<<"iata: "<<iata<<endl;
    cout<<"icao: "<<icao<<endl;
    cor.print_cor();

}
    
Airport::Airport() {
    airport_id = 0;
    name = "default";
    country = "default";
    city = "default";
    iata = "default";
    icao = "default";
    cor = Coordinate(0, 0);

}

Airport::Airport(int set_id, string set_name, string set_city
                , string set_country, string set_iata, string set_icao
                , double lat, double lon) {
    airport_id = set_id;
    name = set_name;
    city = set_city;
    country = set_country;
    iata = set_iata;
    icao = set_icao;
    cor = Coordinate(lat, lon);
}

void Airport::split(const string & s, string c, vector<string> & v) {
    int i = 0;
    int j=s.find(c);
    if (s == "") return;
    while(j > 0 ) {
        v.push_back(s.substr(i, j-i));
        i = ++j;
        j = s.find(c, j);
    }
}


//return the vector of all airports;
//modify the map of aiport ID and airport object
vector<Airport> Airport::parse_airports_from_file(map<string, Airport> the_map) {
    ifstream file;
    file.open("airports.dat.txt");
    string line;
    vector<Airport> all_airports;
    while (getline(file, line)) {
        vector<string> v;
        if (line == "") {
            break;
        }
        split(line, ",", v);
        try{
            Airport cur = Airport(std::stod(v[0]), v[1], v[2], v[3], v[4], v[5]
                            , std::stod(v[6]), std::stod(v[7]));
            all_airports.push_back(cur);
            the_map.insert(pair<string, Airport>(cur.iata, cur));
        } catch (const std::exception& e) {
            cout<<e.what()<<endl;
        }
    }
    file.close();
    return all_airports;
}



