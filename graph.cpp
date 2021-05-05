#include "graph.h"

/*
Graph::Graph() {
    weighted = true;
    directed = false;
    mutable unordered_map<Airport, unordered_map<Airport, route>>() a;
    adjacency = a;


}

vector<Airport> Graph::getAdjacent(Airport source) const 
{
    auto lookup = adjacency.find(source);

    if(lookup == adjacency.end()){
        return vector<Airport>();
    } else {
        vector<Airport> list;
        unordered_map <Airport, route> & a = adjacency[source];
        for (auto it = a.begin(); it != a.end(); it++)
        {
            list.push_back(it->first);
        }
        return list;
    }
}

void Graph::insertVertex(Airport a) 
{
    removeVertex(a);
    adjacencyt[a] = unordered_map<Airport, route>();
}
















bool Graph::assertVertexExists(Airport v) const
{
    if (adjacency_list.find(v) == adjacency_list.end())
    {
        return false;
    }
    return true;
}

*/