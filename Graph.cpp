//
// Created by decla on 5/2/2019.
//

// No code needs to be changed here.

#include "Graph.h"
#include <iostream>

using namespace std;

void Graph::addVertex(string vertex)
{
    vertices.insert(vertex);
}

void Graph::addEdge(string v1, string v2, int weight)
{
    Edge e;
    e.startVertex = v1;
    e.endVertex = v2;
    e.weight = weight;
    edges[v1].push_back(e);
}

list<Edge> Graph::getEdges(string vertex) const
{
    return edges.at(vertex);
};

int Graph::getWeight(string v1, string v2) const
{
    for (Edge e : edges.at(v1))
    {
        if (e.endVertex == v2)
            return e.weight;
    }
    return -1;
}

void Graph::print() const
{
    cout << "Vertices: ";
    for (string v : vertices)
    {
        cout << v << " ";
    }
    cout << "\nEdges: \n";
    for (string v : vertices)
    {
        if (edges.count(v) > 0)
        {
            for (Edge e : edges.at(v))
            {
                cout << v << " -> " << e.endVertex << ": " << e.weight << endl;
            }
        }
    }
}

set<string> Graph::getVertices() const
{
    return vertices;
}

