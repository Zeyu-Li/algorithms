/* 
* Tests by Andrew Li
* Description: A test for all the classes
*/ 
#include <iostream>
#include "../alg/lcm.cpp"
#include "../alg/q_sqrt.cpp"
#include "../alg/bfs.cpp"
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

    // bfs
    
    /* list graph */
    cout << "List graph:" << endl;
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
    vector<int> path;
    graph_l.print();
    graph_l.bfs(source);
    cout << "Length: " << graph_l.bfs_path(source, dest, path) << endl;

    // print
    cout << "Shortest path: ";
    for(int i=0; i<path.size(); ++i) cout << path[i] << ' ';

    return 0;
}
