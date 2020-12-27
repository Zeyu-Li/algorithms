#include <vector>

class Graph {
    int capacity;

    // pointer to vector containing adjacency list
    std::vector<int> *connecting;
    public:
        // contructor with max nodes in graph
        Graph(int capacity);
        // destructor
        ~Graph();

        // adds an edge to graph
        void add_edge(int start, int end);

        // print graph to iostream
        void print();
};

Graph::Graph(int capacity) {
    this->capacity = capacity;

    // allocs for new graph
    connecting = new std::vector<int>[capacity];
}

Graph::~Graph() {
    delete[] connecting;
}

void Graph::add_edge(int start, int end) {
    connecting[start].push_back(end);
}

void Graph::print(void) {
    for (auto connection: this->connecting) {

    }
}
