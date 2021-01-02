// regular graph representation as a array of pairs (source and desinations) and the weight
// https://gist.github.com/MagallanesFito/791f736a0d21708794aafa11a0416201
#include <iostream>
#include <vector>
#include <utility>

template<class T>
class Graph {
    protected:
        // have no uses for now
        int V, E;

        // pointer to vector containing adjacency list
        std::vector<std::pair<T, std::pair<int, int>>> edges;
    public:
        // contructor
        Graph();
        Graph(int V, int E);
        // destructor not needed
        // ~Graph();

        // adds an edge to graph, default weight 1
        void add_edge(int start, int end);
        // overloads with weight
        void add_edge(int start, int end, T weight);

        // print graph to iostream (connection then weight in brackets)
        void print();
};

template<class T>
Graph<T>::Graph(int V, int E) {
    this->V = V;
    this->E = E;
}
template<class T>
Graph<T>::Graph() {
    V = 0;
    E = 0;
}

template<class T>
void Graph<T>::add_edge(int start, int end) {
    edges.push_back({1, {start, end}});
}
template<class T>
void Graph<T>::add_edge(int start, int end, T weight) {
    edges.push_back({weight, {start, end}});
}

template<class T>
void Graph<T>::print(void) {
    typename std::vector<std::pair<T, std::pair<int, int>>>::iterator it;
    for(it = edges.begin();it!=edges.end();it++){
        std::cout << it->second.first << " - " << it->second.second << " (" << it->first << ")" << std::endl;
    }
}
