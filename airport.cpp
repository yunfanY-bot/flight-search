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


/**
 * @brief print all variables of an airport in a formatted way
 */
void Airport::print_airport() {//print out all the variables of airports
    cout<<"Airport ID: " <<airport_id<<endl;
    cout<<"name: " <<name<<endl;
    cout<<"country: " <<country<<endl;    
    cout<<"City: "<<city<<endl;
    cout<<"iata: "<<iata<<endl;
    cout<<"icao: "<<icao<<endl;
    cor.print_cor();

}

/**
 * @brief default constructor
 */
Airport::Airport() 
    : airport_id(0)
    , name("default")
    , country("default")
    , city("default")
    , iata("default")
    , icao("default")
    , cor() 
    { }

/**
 * @brief constructor
 * 
 * @param set_id // the depature iata code 
 * @param set_name // airport name
 * @param set_city // city name
 * @param set_country // country
 * @param set_iata // iata code
 * @param set_icao // icao code
 * @param lat // latitude
 * @param lon // longitude
 */
Airport::Airport(int set_id, string set_name, string set_city
                , string set_country, string set_iata, string set_icao
                , long double lat, long double lon)
    : airport_id(set_id)
    , name(set_name)
    , country(set_country)
    , city(set_city)
    , iata(set_iata)
    , icao(set_icao)
    , cor(lat, lon) 
    { }

/**
 * @brief copy constructor
 * @param other // the other airport
 */
Airport::Airport(const Airport& other)
{
    copy(other);
}

/**
 * @brief equals operator
 * @param other // the other airport
 */
Airport& Airport::operator=(const Airport& other)
{
    copy(other);
    return *this;
}

/**
 * @brief copy helper func
 * @param other // the other airport
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

/**
 * @brief split a string helper func
 * @param s // string to be splited
 * @param c // where to split
 * @param v // a vector of splited string, modified by this function
 */
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

/**
 * @brief // parse all airport data and modify the map of aiport ID and airport object
 * @param s // the other airport
 * @return a vector containing all airports
 */

vector<Airport> Airport::parse_airports_from_file() {
    ifstream file;
    file.open("airports.dat.txt");
    string line;
    vector<Airport> all_airports;
    while (getline(file, line)) {
        vector<string> v;
        //if file end is reached, terminate
        if (line == "") {
            break;
        }
        split(line, ",", v);
        try{
            //if iata code does not exist, jump to next
            if (v[4] == "\\N" || v[5] == "\\N") continue;
            Airport cur = Airport(std::stod(v[0]), v[1].substr(1, v[1].length() - 2)
                            , v[2].substr(1, v[2].length() - 2)
                            , v[3].substr(1, v[3].length() - 2)
                            , v[4].substr(1, v[4].length() - 2)
                            , v[5].substr(1, v[5].length() - 2)
                            , std::stod(v[6]), std::stod(v[7]));
            all_airports.push_back(cur);
            //link id and iata code to airport object
            the_map.insert(pair<string, Airport>(cur.iata, cur));
            the_id_map.insert(pair<int, Airport>(cur.airport_id, cur));
        } catch (const std::exception& e) {
            cout<<e.what()<<endl;
        }
    }
    file.close();
    return all_airports;
}

