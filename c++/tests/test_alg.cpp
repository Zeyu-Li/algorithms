/* 
* Testing Algorithms
* Description: A test for all the algorithm classes
*/ 
#include <limits.h>
#include "../alg/a_star.cpp"
#include "../alg/lcm.cpp"
#include "../alg/q_sqrt.cpp"
#include "../alg/bfs.cpp"
#include "../alg/dfs.cpp"
#include "../alg/dijkstra.cpp"
#include "../alg/bellman_ford.cpp"
#include "../alg/floyd_warshall.cpp"
#include "../alg/kruskal_node.cpp"
#include "../alg/kruskal_matrix.cpp"
#include "../alg/prim.cpp"

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
    Graph_bfs Bfs(true, size);
    Bfs.add_edge(0, 1);
    Bfs.add_edge(0, 3);
    Bfs.add_edge(1, 2);
    Bfs.add_edge(3, 4);
    Bfs.add_edge(3, 7);
    Bfs.add_edge(4, 5);
    Bfs.add_edge(4, 7);
    Bfs.add_edge(5, 6);
    Bfs.add_edge(6, 7);
    int source = 0, dest = 7;
    vector<int> path_bfs1;
    vector<int> path_bfs2;
    // Bfs.print();
    Bfs.bfs(source, path_bfs1);
    cout << "Length: " << Bfs.bfs_path(source, dest, path_bfs2) << endl;

    // print
    cout << "BFS order: ";
    for(int i=0; i<path_bfs1.size(); ++i) cout << path_bfs1[i] << ' ';
    cout << endl;
    cout << "Shortest path: ";
    for(int i=0; i<path_bfs2.size(); ++i) cout << path_bfs2[i] << ' ';
    cout << endl;

    cout << "DFS:" << endl;
    Graph_dfs Dfs(true, 4);
    Dfs.add_edge(0, 1);
    Dfs.add_edge(0, 2);
    Dfs.add_edge(1, 2);
    Dfs.add_edge(2, 0);
    Dfs.add_edge(2, 3);
    Dfs.add_edge(3, 3);
    // Dfs.print();
    vector<int> path_dfs1;
    vector<int> path_dfs2;
    Dfs.dfs(2, path_dfs1);
    // print
    cout << "DFS order: ";
    for(int i=0; i<path_dfs1.size(); ++i) cout << path_dfs1[i] << ' ';
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

    /* A Star */
    cout << "A Star (A*) [g-score]:" << endl;
    Graph_a_star A_Star(false, 9);
    A_Star.add_edge(0, 1, 4);
    A_Star.add_edge(0, 7, 8);
    A_Star.add_edge(1, 2, 8);
    A_Star.add_edge(1, 7, 11);
    A_Star.add_edge(2, 3, 7);
    A_Star.add_edge(2, 5, 4);
    A_Star.add_edge(2, 8, 2);
    A_Star.add_edge(3, 4, 9);
    A_Star.add_edge(3, 5, 14);
    A_Star.add_edge(4, 5, 10);
    A_Star.add_edge(5, 6, 2);
    A_Star.add_edge(6, 7, 1);
    A_Star.add_edge(6, 8, 6);
    A_Star.add_edge(7, 8, 7);

    // defining postions
    vector<pair<int, int>> postions;
    postions.emplace_back(0, 0);
    postions.emplace_back(0, 0);
    postions.emplace_back(0, 0);
    postions.emplace_back(0, 0);
    postions.emplace_back(0, 0);
    postions.emplace_back(0, 0);
    postions.emplace_back(0, 0);
    postions.emplace_back(0, 0);
    postions.emplace_back(100, 100);

    vector<pair<int, int>> postions1;
    postions1.emplace_back(0, 0);
    postions1.emplace_back(73, 82);
    postions1.emplace_back(34, 70);
    postions1.emplace_back(7, 4);
    postions1.emplace_back(5, 36);
    postions1.emplace_back(0, 80);
    postions1.emplace_back(5, 50);
    postions1.emplace_back(100, 100);
    postions1.emplace_back(100, 5);

    A_Star.define_positions(postions1);
    
    // Dijkstra.print();
    vector<int> d_path_2;
    A_Star.a_star(0, 8, d_path_2);
    for(int i=0; i<d_path_2.size(); ++i) cout << i << ": " << d_path_2[i] << ' ' << endl;
    
    cout << "A Star (A*) [f-score]:" << endl;
    vector<int> d_path_3;
    A_Star.debug = true;
    A_Star.a_star(0, 8, d_path_3);
    for(int i=0; i<d_path_3.size(); ++i) cout << i << ": " << d_path_3[i] << ' ' << endl;

    /* Bellman-Ford */
    cout << "Bellman-Ford:" << endl;
    Graph_bf B_f(5, 8);
    B_f.add_edge(0, 1, -1);
    B_f.add_edge(0, 2, 4);
    B_f.add_edge(1, 2, 3);
    B_f.add_edge(1, 3, 2);
    B_f.add_edge(1, 4, 2);
    B_f.add_edge(3, 2, 5);
    B_f.add_edge(3, 1, 1);
    B_f.add_edge(4, 3, -3);

    // will be same as previous if changed from undirected to directed
    // Graph_bf B_f(9, 14);
    // B_f.add_edge(0, 1, 4);
    // B_f.add_edge(0, 7, 8);
    // B_f.add_edge(1, 2, 8);
    // B_f.add_edge(1, 7, 11);
    // B_f.add_edge(2, 3, 7);
    // B_f.add_edge(2, 5, 4);
    // B_f.add_edge(2, 8, 2);
    // B_f.add_edge(3, 4, 9);
    // B_f.add_edge(3, 5, 14);
    // B_f.add_edge(4, 5, 10);
    // B_f.add_edge(5, 6, 2);
    // B_f.add_edge(6, 7, 1);
    // B_f.add_edge(6, 8, 6);
    // B_f.add_edge(7, 8, 7);

    vector<int> b_path;
    // B_f.print();
    B_f.bell_ford(0, b_path);
    for(int i=0; i<b_path.size(); ++i) cout << i << ": " << b_path[i] << ' ' << endl;

    /* Floyd-Warshall */
    cout << "Floyd-Warshall:" << endl;
    int size_f = 4;
    Graph_fw F_w(size_f);
    F_w.add_edge(0, 1, 5);
    F_w.add_edge(0, 3, 10);
    F_w.add_edge(1, 2, 3);
    F_w.add_edge(2, 3, 1);

    vector<vector<int>> f_path;
    F_w.floyd_warshall(f_path);
    for (int i=0;i<size_f;i++) {
        for (int j=0;j<size_f;j++) {
            if (f_path[i][j] == INF) {
                cout << "INF" << '\t';
            } else {
                cout << f_path[i][j]<< "\t";
            }
        }
        cout << endl;
    }
    /* Kruskal (edged based) */
    cout << "Kruskal (edged based):" << endl;
    Graph_kruskal_n Kruskal(4, 5);
    Kruskal.add_edge(0, 1, 10);
    Kruskal.add_edge(0, 2, 6);
    Kruskal.add_edge(0, 3, 5);
    Kruskal.add_edge(1, 3, 15);
    Kruskal.add_edge(2, 3, 4);

    Kruskal.kruskal();
    Kruskal.print_mst();

    /* Kruskal (matrix based) */
    cout << "Kruskal (matrix based):" << endl;
    Graph_kruskal_m Kruskal_m(false, 4);
    Kruskal_m.add_edge(0, 1, 10);
    Kruskal_m.add_edge(0, 2, 6);
    Kruskal_m.add_edge(0, 3, 5);
    Kruskal_m.add_edge(1, 3, 15);
    Kruskal_m.add_edge(2, 3, 4);

    // Kruskal_m.print();
    Kruskal_m.kruskal();
    Kruskal_m.print_mst();

    /* Prim's Algorithm */
    cout << "Prim:" << endl;
    Graph_prim Prim(false, 4);
    Prim.add_edge(0, 1, 10);
    Prim.add_edge(0, 2, 6);
    Prim.add_edge(0, 3, 5);
    Prim.add_edge(1, 3, 15);
    Prim.add_edge(2, 3, 4);

    // Prim.print();
    Prim.prim();
    Prim.print_mst();

    return 0;
}
