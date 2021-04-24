#include "airport.h"
#include <iostream>
#include <iostream>
void airport::print_airport() {//print out all the variables of airports
    std::cout<<"name: " <<name<<std::endl;
    std::cout<<"City: "<<city<<std::endl;
    std::cout<<"Country: "<<country<<std::endl;
    std::cout<<"Location: "<<longitude<<", "<<latitude<<endl;
}
