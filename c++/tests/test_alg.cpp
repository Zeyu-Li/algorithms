/* 
* Tests by Andrew Li
* Description: A test for all the classes
*/ 
#include <iostream>
#include "../alg/lcm.cpp"
#include "../alg/q_sqrt.cpp"
#include "../alg/bfs.cpp"
#include "../alg/dijkstra.cpp"
using namespace std;

void print(int size, int arr[]) {
    for (int i = 0; i < size - 2; i++) {
        std::cout << arr[i] << " -> ";
    }
    std::cout << arr[size - 1];
}

int main() {
    /* gcd and lcm/lcd */
    int a = 21, b = 42, c = 75;
    cout << "GCD:" << endl;
    cout << gcd(a,b) << endl;
    cout << "LCM:" << endl;
    cout << lcm(a,c) << endl;

    /* quick square root */
    float num = 10;
    cout << "Quick Square Root:\n" << q_sqrt(num) << " : " << q_sqrt2(num) << endl;

    /* BFS */
    cout << "BFS:" << endl;
    int size = 8;
    Graph_bfs graph_l(true, size);
    graph_l.add_edge(0, 1);
    graph_l.add_edge(0, 3);
    graph_l.add_edge(1, 2);
    graph_l.add_edge(3, 4);
    graph_l.add_edge(3, 7);
    graph_l.add_edge(4, 5);
    graph_l.add_edge(4, 7);
    graph_l.add_edge(5, 6);
    graph_l.add_edge(6, 7);
    int source = 0, dest = 7;
    vector<int> path_bfs1;
    vector<int> path_bfs2;
    // graph_l.print();
    graph_l.bfs(source, path_bfs1);
    cout << "Length: " << graph_l.bfs_path(source, dest, path_bfs2) << endl;

    // print
    cout << "BFS order: ";
    for(int i=0; i<path_bfs1.size(); ++i) cout << path_bfs1[i] << ' ';
    cout << endl;
    cout << "Shortest path: ";
    for(int i=0; i<path_bfs2.size(); ++i) cout << path_bfs2[i] << ' ';
    cout << endl;

    /* Dijkstra */
    cout << "Dijkstra:" << endl;
    Graph_dijkstra Dijkstra(false, 9);
    Dijkstra.add_edge(0, 1, 4);
    Dijkstra.add_edge(0, 7, 8);
    Dijkstra.add_edge(1, 2, 8);
    Dijkstra.add_edge(1, 7, 11);
    Dijkstra.add_edge(2, 3, 7);
    Dijkstra.add_edge(2, 5, 4);
    Dijkstra.add_edge(2, 8, 2);
    Dijkstra.add_edge(3, 4, 9);
    Dijkstra.add_edge(3, 5, 14);
    Dijkstra.add_edge(4, 5, 10);
    Dijkstra.add_edge(5, 6, 2);
    Dijkstra.add_edge(6, 7, 1);
    Dijkstra.add_edge(6, 8, 6);
    Dijkstra.add_edge(7, 8, 7);

    // Dijkstra.print();
    vector<int> d_path;
    Dijkstra.dijkstra(0, d_path);
    for(int i=0; i<d_path.size(); ++i) cout << i << ": " << d_path[i] << ' ' << endl;
    cout << endl;


    return 0;
}
