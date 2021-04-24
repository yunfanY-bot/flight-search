#include "airport.h"
#include "route.h"
#include <fstream>
#include <vector>
#include <iostream>

void split(const string & s, char c, vector<string> & v) {
    int i = 0;
    int j=s.find(c);
    if (s == "") return;
    
    while(j > 0 ) {
        v.push_back(s.substr(i, j-i));
        i = ++j;
        j = s.find(c, j);
    }
}

int main() {
  std::vector<airport> all_airports;
  //read from .dat files
  
  std::vector<route> all_routes;
  //read from .dat file
  char buf[100];
  FILE* airports_file = fopen("airports.dat.txt", "r");
  
  all_routes[0].print_route();
  all_routes[1].print_route();
  return 0;
  
  
  ifstream file;
    file.open("airports.dat");
    string line;
    std::vector<airport> all_airports;
    std::vector<route> all_routes;

    while (std::getline(file, line)) {
        vector<string> v;
        if (line == "") {
            break;
        }
        split(line, ',', v);
        v[1] = v[1].substr(1, v[1].length() - 2);
        v[2] = v[2].substr(1, v[2].length() - 2);
        v[4] = v[4].substr(1, v[4].length() - 2);
        try{
            if (v[4] == "") continue;
            all_airports.push_back(airport(v[1], v[2], std::stod(v[6]), std::stod(v[7]), v[4]));
        } catch (std::invalid_argument) {
            continue;
        }
    }
    file.close();
}
