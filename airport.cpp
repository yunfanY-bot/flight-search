#include "airport.h"
#include <string>
#include <fstream>
#include <iostream>
#include <map>
#include "coordinate.h"
#include <vector>

using namespace std;

extern map<string, Airport> the_map;

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
                , double lat, double lon) {
    airport_id = set_id;
    name = set_name;
    city = set_city;
    country = set_country;
    iata = set_iata;
    icao = set_icao;
    cor = Coordinate(lat, lon);
}

Airport::Airport(const Airport& other)
{
    copy(other);
}

Airport& Airport::operator=(const Airport& other)
{
    copy(other);
    return *this;
}

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
    int count = 0;
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
            count++;
        } catch (const std::exception& e) {
            cout<<e.what()<<endl;
        }
    }
    file.close();
    return all_airports;
}



