#include "airport.h"
#include "route.h"
#include <vector>
#include <iostream>
int main() {
  std::vector<airport> all_airports;
  //read from .dat files
  while(1) {

  }
  for (airport each_airport : all_airports) {
    each_airport.print_airport();
  }
  std::vector<route> all_routes;
  //read from .dat file
  for (route each_route : all_routes) {
    each_route.print_route();
  }
  return 0;
}
