#include "graph.h"

const Airport Graph::InvalidVertex = Airport();


Graph::Graph(vector<Airport> set_all_airports, vector<route> set_all_routes)
{
    all_airports.
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
    adjacency[a] = unordered_map<Airport, route>();
}

/*

Airport Graph::removeVertex(Airport v)
{

    if (adjacency.find(v) != adjacency.end())
    {
        if(!directed){
            for (auto it = adjacency[v].begin(); it != adjacency[v].end(); it++)
            {
                Airport u = it->first;
                adjacency[u].erase(v); 
            }
            adjacency.erase(v);
            return v;
        }
        
        adjacency.erase(v);
        for(auto it2 = adjacency.begin(); it2 != adjacency.end(); it2++)
        {
            Airport u = it2->first;
            if (it2->second.find(v)!=it2->second.end())
            {
                it2->second.erase(v);
            }
        }
        return v;
    }
    return InvalidVertex;//return empty airport 

}
*/


bool Graph::ifVertexExists(Airport v) const
{
    if (adjacency.find(v) == adjacency.end())
    {
        return false;
    }
    return true;
}


bool Graph::ifEdgeExists(Airport source, Airport destination) const
{
    if(ifVertexExists(source) == false)
        return false;
    if(adjacency[source].find(destination)== adjacency[source].end())
    {
        
        return false;
    }
    if(!directed)
    {
        if (ifVertexExists(destination) == false)
            return false;
        if(adjacency[destination].find(source)== adjacency[destination].end())
        {
            
            return false;
        }
    }
    return true;
}

route getRoutes(Airport source, Airport destination) const
{
    vector<route> tmp;
    for(route route1 : all_routes) {
        if (route1.depature_id == depa) {
            tmp.push_back(route1);
        }
    }   
    for(route route1 : tmp) {
        if (route1.destination_id == dest) {
            return route1;
        }
    }    
    return route();
}