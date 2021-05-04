#include "airport.h"
#include <string>
#include <iostream>
#include "coordinate.h"

using namespace std;

void Airport::print_airport() {//print out all the variables of airports
    cout<<"name: " <<name<<endl;
    cout<<"City: "<<city<<endl;
    cout<<"Country: "<<country<<endl;
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

Airport::Airport(int set_id, string set_name, string set_country
                , string set_city, string set_iata, string set_icao
                , double lat, double lon) {
    airport_id = set_id;
    name = set_name;
    city = set_city;
    country = set_country;
    iata = set_iata;
    icao = set_icao;
    cor = Coordinate(lat, lon);
}

