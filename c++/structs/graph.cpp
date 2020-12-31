// regular graph representation as a array of pairs (source and desinations) and the weight
// https://gist.github.com/MagallanesFito/791f736a0d21708794aafa11a0416201
#include <iostream>
#include <vector>
#include <utility>

class Graph {
    private:
        int V, E;

        // pointer to vector containing adjacency list
        std::vector<std::pair<int, std::pair<int, int>>> edges;
    public:
        // contructor
        Graph();
        Graph(int V, int E);
        // destructor not needed
        // ~Graph();

        // adds an edge to graph, default weight 1
        void add_edge(int start, int end);
        // overloads with weight
        void add_edge(int start, int end, int weight);

        // print graph to iostream (connection then weight in brackets)
        void print();
};

Graph::Graph(int V, int E) {
    this->V = V;
    this->E = E;
}
Graph::Graph() {
    V = 0;
    E = 0;
}

void Graph::add_edge(int start, int end) {
    edges.push_back({1, {start, end}});
}
void Graph::add_edge(int start, int end, int weight) {
    edges.push_back({weight, {start, end}});
}

void Graph::print(void) {
    std::vector<std::pair<int, std::pair<int, int>>>::iterator it;
    for(it = edges.begin();it!=edges.end();it++){
        std::cout << it->second.first << " - " << it->second.second << " (" << it->first << ")" << std::endl;
    }
}

int main() {
    Graph graph;

    graph.add_edge(2, 4,10);
    graph.add_edge(4,3);
    graph.print();
    return 0;
}

