#include "airport.h"
#include "route.h"
#include <fstream>
#include <vector>
#include <iostream>
int main() {
  std::vector<airport> all_airports;
  //read from .dat files
  
  std::vector<route> all_routes;
  //read from .dat file
  while(1) {
    std::ifstream infile("airports.dat.txt");
    
  }
  all_routes[0].print_route();
  all_routes[1].print_route();
  return 0;
}
