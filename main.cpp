#include "airport.h"
#include "route.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <string>

using namespace std;
/*
void split(const string & s, string c, vector<string> & v) {
    int i = 0;
    int j=s.find(c);
    if (s == "") return;
    while(j > 0 ) {
        v.push_back(s.substr(i, j-i));
        i = ++j;
        j = s.find(c, j);
    }
}
*/
int main() { 
    Airport cur = Airport();
    /*
    ifstream file;
    file.open("airports.dat");
    string line;
    vector<Airport> all_airports;
    vector<route> all_routes;

    while (getline(file, line)) {
        vector<string> v;
        if (line == "") {
            break;
        }
        split(line, ",", v);
        v[1] = v[1].substr(1, v[1].length() - 2);
        v[2] = v[2].substr(1, v[2].length() - 2);
        v[4] = v[4].substr(1, v[4].length() - 2);
        try{
            if (v[4] == "") continue;
            Airport cur = Airport(std::stod(v[0]), v[1], v[2], v[3], v[4], v[5]
                            , std::stod(v[6]), std::stod(v[7]));
            all_airports.push_back(cur);
        } catch (std::invalid_argument) {
            cout<<"error"<<endl;
        }
        
        if (v[4] == "") continue;
        Airport cur = Airport(stod(v[0]), v[1], v[2], v[3], v[4], v[5]
                            , stod(v[6]), stod(v[7]));
        all_airports.push_back(cur);

    }
    file.close();
    */
}