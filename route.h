#progma once
#include <string>
#include "airport.h"
class route {
public:
    airport depature;
    airport destination;
    bool is_air;
    double distance;
    //double weight;

    void print_route();
}
