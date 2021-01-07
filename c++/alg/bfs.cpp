/* bfs by Andrew Li */ 
#include "../structs/list_graph.cpp"
#include <climits>
#include <queue>
#include <vector>
#include <algorithm>


class Graph_bfs: public Graph_l {
    protected:
        bool helper_bfs(int, int, std::vector<int>&, std::vector<int>&);
    public:
        // inheritance
        Graph_bfs(bool a, int b): Graph_l(a, b){};
        Graph_bfs(int b): Graph_l(b){};
        // BFS, given starting node, returns vector of ints
        std::vector<int> bfs(int);
        // stores bfs order in second arg, a vector of int, no returns
        void bfs(int, std::vector<int>&);
        // returns shortest length path given start and end node
        int bfs(int, int);
        // returns shortest path length and stores the path in an 
        // vector given by the third arg in the order of source node to end node 
        int bfs_path(int, int, std::vector<int>&);
        // returns the shortest path as a vector
        std::vector<int> bfs_path(int, int);
};

void Graph_bfs::bfs(int start, std::vector<int>&path) {
    std::vector<bool> visited(size);
    std::fill_n(visited.begin(), size, false);
    // might as well use vectors
    // bool *visited = new bool[size];
    // // zeros bool array
    // memset(visited, 0, sizeof(bool) * (size));

    std::queue<int> list;

    // starting node
    visited[start] = true;
    list.push(start);

    // while queue is not empty
    while (!list.empty()) {
        // sets new node as first in queue
        start = list.front();
        // prints order
        path.push_back(start);
        // dequeues
        list.pop();

        // gets all adjacent vertices
        for (std::vector<int>::iterator i = adj[start].begin(); i != adj[start].end(); ++i) {
            if (!visited[*i]) {
                visited[*i] = true;
                list.push(*i);
            }
        }
    }
}

std::vector<int> Graph_bfs::bfs(int start) {
    std::vector<int> path;
    bfs(start, path);
    return path;
}

int Graph_bfs::bfs(int start, int end) {
    std::vector<int> path;
    return bfs_path(start, end, path);
}

int Graph_bfs::bfs_path(int start, int end, std::vector<int> &path) {
    std::vector<int> dist(size);
    std::vector<int> pred(size);
    // zeros bool and int array
    fill_n(dist.begin(), size, INT_MAX);
    fill_n(pred.begin(), size, -1);

    if (!helper_bfs(start, end, pred, dist)) {
        // not connected, return max int
        return INT_MAX;
    }

    // debugs
    // for(int i=0; i<pred.size(); ++i) std::cout << pred[i] << ' ';
    // std::cout << '\n';
    // for(int i=0; i<dist.size(); ++i) std::cout << dist[i] << ' ';

    int trace = end;
    path.push_back(trace);
    while (pred[trace] != -1) {
        path.push_back(pred[trace]);
        trace = pred[trace];
    }
    // reverse order of path
    std::reverse(path.begin(), path.end());
    return dist[end];
}

bool Graph_bfs::helper_bfs(int start, int end, std::vector<int> &pred, std::vector<int> &dist) {
    std::vector<bool> visited(size);
    // zeros bool array
    fill_n(visited.begin(), size, false);

    // starting node
    std::queue<int> list;
    visited[start] = true;
    dist[start] = 0;
    list.push(start);

    // while queue is not empty
    while (!list.empty()) {
        // sets new node as first in queue
        int u = list.front();
        // dequeues
        list.pop();

        // gets all adjacent vertices
        for (int i = 0; i < adj[u].size(); i++) {
            // if not visited
            int current = adj[u][i];
            if (!visited[current]) {
                visited[current] = true;
                dist[current] = dist[u]+1;
                pred[current] = u;
                list.push(current);

                if (current == end) {
                    return true;
                }
            }
        }
    }

    return false;
}
