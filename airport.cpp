#include "airport.h"
#include <iostream>
#include <iostream>
void airport::print_airport() {//print out all the variables of airports
    std::cout<<"name: " <<name<<std::endl;
    std::cout<<"City: "<<city<<std::endl;
    std::cout<<"Country: "<<country<<std::endl;
    std::cout<<"Location: "<<longitude<<", "<<latitude<<endl;
}
    
Airport::Airport() {

}

Airport::Airport(std::string n, std::string c, double lat, double lon, std::string id) {
    cord = Coordinate(lat, lon);
    name = n;
    city = c;
    ID = id;
    latitude = lat;
    longitude = lon;
}
