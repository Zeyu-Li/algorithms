/* 
* bfs by Andrew Li
*/ 
#include <iostream>
#include "../structs/list_graph.cpp"
#include <cstring>
#include <queue>


class Graph_bfs: public Graph_l {
    public:
        // inheritance
        Graph_bfs(bool a, int b): Graph_l(a, b){};
        Graph_bfs(int b): Graph_l(b){};
        // BFS, given starting node
        void bfs(int);
        // returns shortest path given start and end node
        int bfs(int, int);
        // returns if BFS is possible to end node 
        // and also stores path into the third array arg
        bool bfs(int, int, int[]);
};

void Graph_bfs::bfs(int start) {
    bool *visited = new bool[size];
    // zeros bool array
    memset(visited, 0, sizeof(bool) * size);

    std::queue<int> list;

    // starting node
    visited[start] = true;
    list.push(start);

    // while queue is not empty
    while (!list.empty()) {
        // sets new node as first in queue
        start = list.front();
        // prints order
        std::cout << start << " ";
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

    delete[] visited;
}


int main() {
    /* list graph */
    std::cout << "List graph:" << std::endl;
    Graph_bfs graph_l(false, 4);
    graph_l.add_edge(1,3);
    graph_l.add_edge(0,2);
    graph_l.add_edge(0,1);
    graph_l.delete_edge(0,2);
    graph_l.add_edge(0,2);
    graph_l.print();
    graph_l.bfs(0);
    return 0;
}
