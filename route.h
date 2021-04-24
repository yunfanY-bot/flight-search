#pragma once
#include <string>
#include "airport.h"
class route {
public:
    std::string airline;
    int airline_id;
    airport depature;
    int depature_id;
    airport destination;
    int destination_id;
    bool is_air;
    double distance;
    //double weight;

    void print_route();
private:
    double calculate_distance;
};
