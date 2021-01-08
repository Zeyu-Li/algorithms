/* 
* Floyd-Warshall
* Modified from: https://www.geeksforgeeks.org/floyd-warshall-algorithm-dp-16/
*/ 
#include <vector>
#include "../structs/matrix_graph.cpp"

#define INF 99999

class Graph_fw: public Graph_m {
    public:
        Graph_fw(): Graph_m() {};
        Graph_fw(bool a): Graph_m(a) {};
        Graph_fw(int a): Graph_m(a) {};
        Graph_fw(bool a, int b): Graph_m(a, b) {};
        // from the source node will return a 
        // matrix of all optimal paths from 1 node to another
        std::vector<std::vector<int>> floyd_warshall(void);
        // stores optimal path matrix in first and only arg, no return
        void floyd_warshall(std::vector<std::vector<int>>&);
};

void Graph_fw::floyd_warshall(std::vector<std::vector<int>>& matrix) {
    matrix = floyd_warshall();
}

std::vector<std::vector<int>> Graph_fw::floyd_warshall() {
    // refactor matrix such that unconnected paths are MAX INT instead of 0
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            // cannot use max int because addition will wrap over
            if (i != j && matrix[i][j] == 0) matrix[i][j] = INF;
        }
    }

    // the dp soltution to every pair 
    std::vector<std::vector<int>> dist(size, std::vector<int>(size));
    // copy vector over
    dist = matrix;

    // minimizes for every connection for every node
    for (int k = 0; k < size; k++) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    return dist;
}