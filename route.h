#pragma once
#include <string>
#include "airport.h"
class route {
public:
    airport depature;
    std::string depature_id;
    airport destination;
    std::string destination_id;
    bool is_air;
    double distance;
    //double weight;

    void print_route();
private:
    void calculate_distance;
};
