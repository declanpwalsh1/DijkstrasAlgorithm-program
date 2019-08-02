//
// Created by decla on 5/2/2019.
//

// No code needs to be changed here.

#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <list>
#include <map>
#include <set>
#include <string>

using namespace std;

/*
 * An Edge represents a single directed edge in the graph.  Each edge has an integer
 * weight associated with it.
 */
struct Edge
{
    string startVertex, endVertex;
    int weight;
};

/*
 * The Graph class represents a directed graph.  Each vertex is represented by a unique string,
 * and edges are represented by pairs of vertices (a starting vertex and an ending vertex), along
 * with an associated integer weight.
 *
 * The vertices are stored as a set, whereas the edges are stored as an adjacency list.  Specifically,
 * we have a map which associates every vertex (a string) with a linked list of edges that *start* at
 * that vertex.  So it's very easy to determine which directed edges leave a given vertex, but a little
 * bit harder to determine which edges enter a given vertex.
 */
class Graph
{
public:
    void addVertex(string vertex);                  // add a vertex to the graph
    void addEdge(string v1, string v2, int weight); // add a edge to the graph
    list<Edge> getEdges(string vertex) const;       // get all the edges that begin at a vertex
    int getWeight(string v1, string v2) const;      // get the weight of an edge in the graph
    set<string> getVertices() const;                // get all the vertices in the graph
    void print() const;                             // print the graph

private:
    set<string> vertices;           // all the vertices in the graph
    map<string, list<Edge>> edges;  // adjacency list to represent edges *leaving* each vertex
};


#endif

