/*
* Regular Graph
* representation as a array of pairs (source and desinations) and the weight
* Modifed from: https://gist.github.com/MagallanesFito/791f736a0d21708794aafa11a0416201
*/
#include <iostream>
#include <vector>
#include <utility>
// remove if necessary
#pragma once

class Graph {
    protected:
        int V, E;
        bool final_e;

        // pointer to vector containing adjacency list (weight, (source, destination))
        std::vector<std::pair<int, std::pair<int, int>>> edges;
    public:
        // contructor
        Graph();
        Graph(int, int);
        // destructor not needed
        // ~Graph();

        // adds an edge to graph, default weight 1
        void add_edge(int start, int end);
        // overloads with weight
        void add_edge(int start, int end, int weight);

        // print graph to iostream (connection then weight in brackets)
        void print();
};

Graph::Graph(int vertex, int edges) {
    V = vertex;
    E = edges;
    final_e = true;
}
Graph::Graph() {
    V = 0;
    E = 0;
    final_e = false;
}

void Graph::add_edge(int start, int end) {
    if (!final_e) E++;
    edges.push_back({1, {start, end}});
}
void Graph::add_edge(int start, int end, int weight) {
    if (!final_e) E++;
    edges.push_back({weight, {start, end}});
}

void Graph::print(void) {
    std::vector<std::pair<int, std::pair<int, int>>>::iterator it;
    for(it = edges.begin();it!=edges.end();it++){
        std::cout << it->second.first << " - " << it->second.second << " (" << it->first << ")" << std::endl;
    }
}
