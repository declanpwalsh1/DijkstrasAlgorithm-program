// The only place you need to add or change
// code is in the dijkstra() function.

#include <iostream>
#include <fstream>
#include <sstream>
#include "Graph.h"
#include "PriorityQueue.h"
#include <vector>
#include <utility>

using namespace std;

vector<string> split(const string &s, char delim);
void dijkstra(const Graph &g, string startv, string endv);

int main()
{
    string filename;
    cout << "What filename do you want to read? ";
    cin >> filename;
    ifstream infile(filename);
    if (infile.fail())
    {
        cout << "Could not open file." << endl;
        exit(0);
    }

    string line;
    bool undirected;
    Graph g;
    while (getline(infile, line))
    {
        vector<string> words = split(line, ' ');

        if (words[0] == "undirected")
            undirected = true;
        else if (words[0] == "directed")
            undirected = false;
        else if (words[0] == "vertex")
        {
            g.addVertex(words[1]);
        }
        else if (words[0] == "edge")
        {
            g.addEdge(words[1], words[2], stoi(words[3]));
            if (undirected)
                g.addEdge(words[2], words[1], stoi(words[3]));
        }
        else if (words[0] == "dijkstra")
        {
            cout << endl; g.print(); cout << endl;
            dijkstra(g, words[1], words[2]);
        }
    }
    infile.close();
}

void dijkstra(const Graph &g, string startv, string endv)
{
    map<string, int> dist;       // shortest distance found so far
    map<string, string> prev;    // previous vertex in best path found so far
    vector<string> shortestPath;
    dist[startv] = 0;
    set<string> vertices = g.getVertices();
    PriorityQueue pq;
    pq.insert(startv, 0);
    set<string> newVerts = g.getVertices();
    for(const auto & v : newVerts){
        if(v != startv){
            dist[v] = 999999999;
            prev[v] = "";
            pq.insert(v, dist[v]);
        }
    }
    while(!pq.isEmpty()){
        string u = pq.extractMin();

        if(u == endv){
            break;
        }
        cout << "visiting" << u << endl;
        for(auto v : g.getEdges(u)){
            string edge1 = v.endVertex;
            //int temporary = dist[edge1];
            int alt = dist[u] + g.getWeight(u, edge1);
            if(alt < dist[edge1]){
                //int prevDist = dist[edge1];
                dist[edge1] = alt;
                prev[edge1] = u;
                if(pq.contains(edge1)){
                    pq.changePriority(edge1, alt);
                } else{
                    pq.insert(edge1, alt);
                }
            }
        }

    }
    for(pair<string, string> p : prev){
        if(find(shortestPath.begin(), shortestPath.end(), p.second) != shortestPath.end()){
            continue;
        } else{
            shortestPath.push_back(p.second);
        }
    }
    shortestPath.push_back(endv);


    cout << endl << "Shortest path is:" << endl;
    for(auto s : shortestPath){
        cout << s << " ";
    }

    cout << endl << "Distance is: " << endl << dist[endv]<< endl;


    cout << "Final dist map:" << endl;
    for (auto pair : dist)
    {
        cout << pair.first << ": " << pair.second << endl;
    }
    cout << "\nFinal prev map:" << endl;
    for (auto pair : prev)
    {
        cout << pair.first << ": " << pair.second << endl;
    }
}

vector<string> split(const string &s, char delim)
{
    stringstream ss(s);  // this requires #include <sstream>
    string item;
    vector<string> elems;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}
