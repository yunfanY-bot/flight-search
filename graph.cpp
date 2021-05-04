#include "graph.h"


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
        unordered_map <Airport, route> & map = adjacency[source];
        for (auto it = map.begin(); it != map.end(); it++)
        {
            list.push_back(it->first);
        }
        return list;
    }
}

void Graph::insertVertex(Airport v) 
{
    removeVertex(v);
    adjacencyt[v] = unordered_map<Airport, route>();
}
















bool Graph::assertVertexExists(Airport v) const
{
    if (adjacency_list.find(v) == adjacency_list.end())
    {
        return false;
    }
    return true;
}

bool Graph::assertEdgeExists(Airport source, Airport destination) const
{
    if(assertVertexExists(source) == false)
        return false;
    if(adjacency_list[source].find(destination)== adjacency_list[source].end())
    {
        return false;
    }
    if(!directed)
    {
        if (assertVertexExists(destination) == false)
            return false;
        if(adjacency_list[destination].find(source)== adjacency_list[destination].end())
        {
            return false;
        }
    }
    return true;
}