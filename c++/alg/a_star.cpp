/* 
* A Star (A*, aka Dijkstra++) Algorithm
* using 2D euclidean distance
*
* Note A Star does not guaranteed to be the shortest path, 
* just a more time efficient solution 
*/ 
#include <algorithm>
#include <limits.h> 
#include "../structs/matrix_graph.cpp"

class Graph_a_star: public Graph_m {
    public:
        Graph_a_star(): Graph_m() {};
        Graph_a_star(bool a): Graph_m(a) {};
        Graph_a_star(int a): Graph_m(a) {};
        Graph_a_star(bool a, int b): Graph_m(a, b) {};
        // returns a vector of the result of a star's alg
        std::vector<int> a_star(int, int);
        // stores a_star results in second argument
        void a_star(int, int, std::vector<int>&);
        // returns shortest path given start and end
        int a_star_length(int, int);

        // pass in a list of form [int node, [int x, int y]] and will be copied not as an instance
        void define_positions(std::vector<std::pair<int, std::pair<int, int>>>);
    private:
        // gets min distance
        int min_dist(std::vector<int>&, std::vector<bool>&);
        std::vector<std::pair<int, std::pair<int, int>>> positions;
        
};


int Graph_a_star::min_dist(std::vector<int>& dist, std::vector<bool>& shortest_path) {
    int min = INT_MAX, min_index;
    // for each vertex
    for (int v = 0; v < size; v++) {
        // if is connected and smaller than current min, swap to that one
        
        // add heuristic? 
        if ((!shortest_path[v]) && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}


std::vector<int> Graph_a_star::a_star(int start, int end) {
    std::vector<int> dist(size); // shortest path distance of each point
    std::fill_n(dist.begin(), size, INT_MAX);
    std::vector<bool> shortest_path(size);
    std::fill_n(shortest_path.begin(), size, false);

    // start of path is of distance 0
    dist[start] = 0;
    // for every vertex
    for (int i = 0; i < size - 1; i++) {
        // gets shortest path to work off of
        int u = min_dist(dist, shortest_path);
        // check the current node
        shortest_path[u] = true;

        // update dist of adjacent vertices to the shortest path if it is connect and shorter than previous entry (dp)
        for (int v = 0; v < size; v++) {
            if (!shortest_path[v] && matrix[u][v] && dist[u] != INT_MAX && dist[u] + matrix[u][v] < dist[v]) {
                dist[v] = dist[u] + matrix[u][v];
            }
        }
        // ends early
        if (u == end) break;
    }
    
    // return the distances of all nodes
    return dist;
}

void Graph_a_star::a_star(int start, int end, std::vector<int>&path) {
    std::vector<int> d_path = a_star(start, end);
    // copy vectors
    for(int i=0; i<d_path.size(); ++i) path.push_back(d_path[i]);
}

/// defines all the positions in 1 function
/// pass in a list of form [int node, [int x, int y]] 
/// will be copied
void Graph_a_star::define_positions(std::vector<std::pair<int, std::pair<int, int>>> positions) {
    // copy vectors
    this->positions = positions;
}

int Graph_a_star::a_star_length(int start, int end) {
    std::vector<int> d_path = a_star(start, end);
    // return length of shortest path
    return d_path.size();
}
