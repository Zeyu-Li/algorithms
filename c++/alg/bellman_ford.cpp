/* Bellman-Ford */ 
#include <iostream>
#include <vector>
#include <iostream>
#include <limits.h>
#include "../structs/graph.cpp"

class Graph_bf: public Graph {
    public:
        Graph_bf(): Graph() {};
        Graph_bf(int V, int E): Graph(V, E) {};
        // stores the results the the bellman ford given source node, (no return value)
        void bell_ford(int, std::vector<int>&);
        // returns a vector of bellman ford results
        std::vector<int> bell_ford(int);
        // returns the length of the path from a source to the destination
        int bell_ford(int, int);
};

int Graph_bf::bell_ford(int start, int end) {
    std::vector<int> result;
    bell_ford(start, result);
    return result[end];
}

std::vector<int> Graph_bf::bell_ford(int start) {
    std::vector<int> result;
    bell_ford(start, result);
    return result;
}

void Graph_bf::bell_ford(int start, std::vector<int>&path) {
    // uses dynamic programming to determine shortest distance
    std::vector<int> dist(V);
    // all nodes unknown so infinite distance
    std::fill_n(dist.begin(), V, INT_MAX);
    // set current to 0
    dist[start] = 0;

    // relaxes all edges V-1 times applying dp
    for (int i = 1; i < V; i++) {
        // for every edges (this makes it O(V+E))
        for (int j = 0; j < E; j++) {
            int u = edges[j].second.first;
            int v = edges[j].second.second;
            int w = edges[j].first;
            // if edge v (destination) is connected and 
            // less than the source node + weight, update destination node 
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) dist[v] = dist[u] + w;
        }
    }

    // check for negative weighted cycles (assumed non negative weight cycles)
    // for (int j = 0; j < E; j++) { 
    //     int u = edges[j].second.first;
    //     int v = edges[j].second.second;
    //     int w = edges[j].first;
    //     if (dist[u] != INT_MAX && dist[u] + w < dist[v]) { 
    //         printf("Graph contains negative weight cycle"); 
    //         // If negative cycle is detected, error out
    //         throw -1;
    //         return;
    //     } 
    // } 

    // copy dist to path (weighted dp table)
    for(int i=0; i<dist.size(); ++i) path.push_back(dist[i]);
    return;
}
