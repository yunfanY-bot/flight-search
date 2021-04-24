#include "airport.h"
#include "route.h"
#include <fstream>
#include <vector>
#include <iostream>
int main() {
  std::vector<airport> all_airports;
  //read from .dat files
  ifstream file;
    file.open("airports.dat");
    string line;
    vector<Airport> airports;
    vector<route> routes;

    while (std::getline(file, line)) {
        vector<string> v;
        if (line == "") {
            break;
        }
          //std::cout << line << std::endl;
        split(line, ',', v);
        v[1] = v[1].substr(1, v[1].length()-2);
        v[2] = v[2].substr(1, v[2].length() - 2);
        v[4] = v[4].substr(1, v[4].length() - 2);
        try{
            if (v[4] == "") continue;
            airports.push_back(Airport(v[1], v[2], std::stod(v[6]), std::stod(v[7]), v[4]));
        } catch (std::invalid_argument) {
            continue;
        }
    }
    file.close();
  
  std::vector<route> all_routes;
  //read from .dat file
  char buf[100];
  FILE* airports_file = fopen("airports.dat.txt", "r");
  
  all_routes[0].print_route();
  all_routes[1].print_route();
  return 0;
}
