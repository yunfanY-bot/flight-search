#include "airport.h"
#include <string>
#include <fstream>
#include <iostream>
#include <map>
#include "coordinate.h"
#include <vector>

using namespace std;

extern map<string, Airport> the_map;
extern map<int, Airport> the_id_map;


void Airport::print_airport() {//print out all the variables of airports
    cout<<"ID: " <<airport_id<<endl;
    cout<<"name: " <<name<<endl;
    cout<<"country: " <<country<<endl;    
    cout<<"City: "<<city<<endl;
    cout<<"iata: "<<iata<<endl;
    cout<<"icao: "<<icao<<endl;
    cor.print_cor();

}
    
Airport::Airport() 
    : airport_id(0)
    , name("default")
    , country("default")
    , city("default")
    , iata("default")
    , icao("default")
    , cor() 
    { }


Airport::Airport(int set_id, string set_name, string set_city
                , string set_country, string set_iata, string set_icao
                , double lat, double lon)
    : airport_id(set_id)
    , name(set_name)
    , country(set_country)
    , city(set_city)
    , iata(set_iata)
    , icao(set_icao)
    , cor(lat, lon) 
    { }

Airport::Airport(const Airport& other)
{
    copy(other);
}

Airport& Airport::operator=(const Airport& other)
{
    copy(other);
    return *this;
}


//WARNING:
//DO NOT use this method. Only used in min heap
/*
bool Airport::operator>(const Airport& other) const {
    if (d == -1 && other.d == -1) {
        return false;
    }
    if (d == -1 && other.d != -1) {
        return true;
    }
    if (d != -1 && other.d == -1) {
        return false;
    }
    if (d != -1 && other.d != -1) {
        return d > other.d;
    }
    
}
*/

void Airport::copy(const Airport& other) {
    airport_id = other.airport_id;
    name = other.name;
    city = other.city;
    country = other.country;
    iata = other.iata;
    icao = other.icao;
    cor.lat = other.cor.lat;
    cor.lon = other.cor.lon;
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
vector<Airport> Airport::parse_airports_from_file() {
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
            if (v[4] == "\\N" || v[5] == "\\N") continue;
            Airport cur = Airport(std::stod(v[0]), v[1].substr(1, v[1].length() - 2)
                            , v[2].substr(1, v[2].length() - 2)
                            , v[3].substr(1, v[3].length() - 2)
                            , v[4].substr(1, v[4].length() - 2)
                            , v[5].substr(1, v[5].length() - 2)
                            , std::stod(v[6]), std::stod(v[7]));
            all_airports.push_back(cur);
            the_map.insert(pair<string, Airport>(cur.iata, cur));
            the_id_map.insert(pair<int, Airport>(cur.airport_id, cur));
        } catch (const std::exception& e) {
            cout<<e.what()<<endl;
        }
    }
    file.close();
    return all_airports;
}

void Airport::set_d(double set_d) {
    d = set_d;
}
void Airport::set_p(int set_p) {
    p = set_p;
}
double Airport::get_d() const {
    return d;
}
int Airport::get_p() const {
    return p;
}

