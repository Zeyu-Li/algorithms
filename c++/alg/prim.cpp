/* 
* Prim's Algorithm
* Modified from: https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/
*/ 
// Already in matrix_graph.cpp
// #include <vector>
#include <utility>
#include <algorithm>
#include <limits.h>
#include "../structs/matrix_graph.cpp"

class Graph_prim: public Graph_m {
    public:
        Graph_prim(): Graph_m() {};
        Graph_prim(bool a): Graph_m(a) {};
        Graph_prim(int a): Graph_m(a) {};
        Graph_prim(bool a, int b): Graph_m(a, b) {};
        // applied prim's algorithm to get MST 
        // (MST will be stored in a vector of 
        // pair(int weight, pair(int source, int destination))) 
        void prim(void);
        // minimum spanning tree
        std::vector<std::pair<int, std::pair<int, int>>> MST;
        void print_mst();
    private:
        int min_key(std::vector<int>&, std::vector<bool>&);
        std::vector<int> parent;
};

int Graph_prim::min_key(std::vector<int>& key, std::vector<bool>& set_MST) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < size; v++) {
        // if not in the mst and lower than the current min, set new min
        if (!set_MST[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void Graph_prim::prim() {
    // resize vector
    parent.resize(size);
    
    // key for picking minimum weight edge in cut
    std::vector<int> key(size);
    // represent the edges in the MST if counted
    std::vector<bool> set_MST(size);
    // inits keys as infinite and all vertices as not visited
    std::fill_n(key.begin(), size, INT_MAX);
    std::fill_n(set_MST.begin(), size, false);

    // starting node
    key[0] = 0;
    parent[0] = -1;

    // for every node
    for (int count = 0; count < size - 1; count ++) {
        // pick minimum key from vertices not in MST (that are connected)
        int u = min_key(key, set_MST);

        // picked vertex in mst set
        set_MST[u] = true;
        for (int v = 0; v < size; v++) {
            if (matrix[u][v] && !set_MST[v] && matrix[u][v] < key[v]) {
                parent[v] = u;
                key[v] = matrix[u][v];
            }
        }
    }

    // store in MST
    for (int i = 1; i < size; i++) {
        MST.push_back({matrix[i][parent[i]], {parent[i], i}});
    }
}

void Graph_prim::print_mst(void) {
    // std::vector<std::pair<int, std::pair<int, int>>>::iterator it;
    for(auto it = MST.begin();it!=MST.end();it++){
        std::cout << it->second.first << " - " << it->second.second << " (" << it->first << ")" << std::endl;
    }
}
