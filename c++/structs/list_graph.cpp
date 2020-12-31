/* 
* Adjacency List Graph by Andrew Li
* https://www.geeksforgeeks.org/graph-and-its-representations/ & from hash table
*/ 
#include <iostream>
#include <vector>

class Graph_l {
    private:
        bool directed;
        // hash table list
        std::vector<int> *adj;
        int size;
        bool flag = false;
    public:
        // contructor, first arg directed or undirected, next is the number of vertices
        Graph_l(bool, int);
        // overloads main contructor, default undirected
        Graph_l(int);

        // add edge
        void add_edge(int source, int destination);
        // TODO: add list of pairs?
        // void add_edges(std::pairs);
        void delete_edge(int source, int destination);

        // gets size of graph (ie number of vertices)
        int get_size();
        // print
        void print();
        // print all edges to a vertix
        void print_edges(int);
};

Graph_l::Graph_l(int v) {
    directed = true;
    size = v;
    adj = new std::vector<int>[v];
}
Graph_l::Graph_l(bool dir, int v) {
    directed = dir;
    size = v;
    adj = new std::vector<int>[v];
}

void Graph_l::add_edge(int source, int destination) {
    adj[source].push_back(destination);
    // if undirected, also do the reverse
    if (!directed) adj[destination].push_back(source);
}

void Graph_l::delete_edge(int source, int destination) {
    // iterate through table by rows
    std::vector<int> :: iterator i;
    for (i = adj[source].begin(); i != adj[source].end(); i++) {
        if (*i == destination) break;
    }

    if (i != adj[source].end()) adj[source].erase(i);
    // if undirected, do the reverse
    if (!directed && !flag) {
        flag = !flag;
        delete_edge(destination, source);
        flag = !flag;
    }
}

void Graph_l::print() {
    for (int i = 0; i<size; i++) {
        std::cout << i;
        for (auto item: adj[i]) {
            std::cout << " -> " << item;
        }
        std::cout << std::endl;
    }
}
void Graph_l::print_edges(int edge) {
    std::cout << edge;
    for (auto item: adj[edge]) {
        std::cout << " -> " << item;
    }
    std::cout << std::endl;
}
int Graph_l::get_size() {
    return size;
}

int main() {
    Graph_l graph(false, 4);
    graph.add_edge(1,3);
    graph.add_edge(0,2);
    graph.add_edge(0,1);
    graph.delete_edge(0,2);
    graph.print();
    graph.add_edge(0,2);
    graph.print_edges(0);
    return 0;
}