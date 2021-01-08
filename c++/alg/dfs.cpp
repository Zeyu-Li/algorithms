/* DFS */ 
// #include <vector>
#include <climits>
#include <queue>
#include <algorithm>
#include "../structs/list_graph.cpp"

class Graph_dfs: public Graph_l {
    protected:
        void helper_dfs(int, std::vector<bool>&);
        std::vector<int> path; 
    public:
        // inheritance
        Graph_dfs(bool a, int b): Graph_l(a, b){};
        Graph_dfs(int b): Graph_l(b){};
        // DFS, given starting node, returns vector of ints
        std::vector<int> dfs(int);
        // stores dfs order in second arg, a vector of int, no returns
        void dfs(int, std::vector<int>&);
};

void Graph_dfs::dfs(int start, std::vector<int>&path) {
    path = dfs(start);
}

std::vector<int> Graph_dfs::dfs(int start) {
    // inits
    std::vector<bool> visited(size);
    std::fill_n(visited.begin(), size, false);

    helper_dfs(start, visited);

    return path;
}

void Graph_dfs::helper_dfs(int start, std::vector<bool> &visited) {
    visited[start] = true;
    path.push_back(start);

    // while queue is not empty
    for (auto i = adj[start].begin(); i != adj[start].end(); ++i) {
        if (!visited[*i]) helper_dfs(*i, visited);
    }
}
