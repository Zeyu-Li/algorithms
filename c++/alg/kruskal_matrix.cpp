/* 
* Kruskal's Algorithm for Matrix/Table Graph
* Modified from: https://www.geeksforgeeks.org/kruskals-algorithm-simple-implementation-for-adjacency-matrix/
*/ 
// Already in matrix_graph.cpp
// #include <vector>
#include <utility>
#include <algorithm>
#include <limits.h>
#include "../structs/matrix_graph.cpp"

class Graph_kruskal_m: public Graph_m {
    public:
        Graph_kruskal_m(): Graph_m() {};
        Graph_kruskal_m(bool a): Graph_m(a) {};
        Graph_kruskal_m(int a): Graph_m(a) {};
        Graph_kruskal_m(bool a, int b): Graph_m(a, b) {};
        // applied kruskal's algorithm to get MST 
        // (MST will be stored in a vector of 
        // pair(int weight, pair(int source, int destination))) 
        void kruskal(void);
        // minimum spanning tree
        std::vector<std::pair<int, std::pair<int, int>>> MST;
        void print_mst();
    private:
        int find(int);
        void union_(int, int);
        std::vector<int> parent;
};

int Graph_kruskal_m::find(int i) {
    while (parent[i] != i) {
        i = parent[i];
    }
    return i;
}

void Graph_kruskal_m::union_(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

void Graph_kruskal_m::kruskal() {
    // refactor matrix such that unconnected paths are MAX INT instead of 0
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            // cannot use max int because addition will wrap over
            if (matrix[i][j] == 0) matrix[i][j] = INT_MAX;
        }
    }
    // resize vector
    parent.resize(size);
    // initialize disjoint set
    for (int i = 0; i < size; i++) parent[i] = i;

    for (int edge_count = 0; edge_count < size - 1; edge_count++) {
        int min = INT_MAX, a, b;
        a = b = -1;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (find(i) != find(j) && matrix[i][j] < min) {
                    min = matrix[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        // join union a and b
        union_(a, b);
        MST.push_back({min, {a, b}});
    }
}

void Graph_kruskal_m::print_mst(void) {
    std::vector<std::pair<int, std::pair<int, int>>>::iterator it;
    for(it = MST.begin();it!=MST.end();it++){
        std::cout << it->second.first << " - " << it->second.second << " (" << it->first << ")" << std::endl;
    }
}
