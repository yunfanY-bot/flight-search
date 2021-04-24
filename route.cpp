#include "route.h"
#include <iostream>
void route::print_route() {//print all variables of a route
    std::cout<< <<endl;
}

double route::calculate_distance() {//calculate route distance

}


route::route() {}
route::route(Airport s, Airport d, double w) : source(s), dest(d), weight(w) {}
