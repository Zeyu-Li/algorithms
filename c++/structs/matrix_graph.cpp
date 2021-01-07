/* 
* Matrix/Table Graph
* Modified from: https://github.com/DorianDepriester/adjacencyMatrix
*/
#include <iostream>
#include <vector>

class Graph_m {
    public:
        // contructors, default undirected
        Graph_m();
        // contructor with directness boolean 
        Graph_m(bool);
        // contructor with size (number of vertices)
        Graph_m(int);
        Graph_m(bool, int);
        // destructor
        ~Graph_m();

        // print
        void print();
        int get_size();

        // resize
        void resize(int new_size);

        // setter (edge)
        void add_edge(int, int);
        // overloads when default weight is not 1
        void add_edge(int, int, int);

        // main matrix, therefore getter unnecessary
        std::vector<std::vector <int>> matrix;
    protected:
        int size;
        bool directed;
};

Graph_m::Graph_m() {
    size=0;
    directed = true;
}
Graph_m::Graph_m(bool direc) {
    size=0;
    directed = direc;
}
Graph_m::Graph_m(int n) {
    directed = true;
    // resize
    size=0;
    resize(n);
    size=n;
}
Graph_m::Graph_m(bool direc, int n) {
    directed = direc;
    // resize
    size=0;
    resize(n);
    size=n;
}
Graph_m::~Graph_m() {
    size=0;
}

// resize
void Graph_m::resize(int new_size) {
    if (new_size > size) {
        // enlarge the matrix
        for (int i = size; i<new_size; i++) {
            // add zero to each row
            // zeros for each row
            std::vector<int> bottom;
            for (int j = size; j<new_size; j++) {
                bottom.push_back(0);
            }
            matrix.push_back(bottom);
        }
    }
}

// add edge row then column
void Graph_m::add_edge(int y, int x) {
    // sets size as the max of x or y
    int max = x > y ? x : y;
    if (max>size) {
        size = max;
        // Resize
        resize(max);
    }
    matrix[y][x] = 1;
    // if undirected
    if (!directed) matrix[x][y] = 1;
}
void Graph_m::add_edge(int y, int x, int weight) {
    // sets size as the max of x or y
    int max = x > y ? x : y;
    if (max>size) {
        size = max;
    }
    matrix[y][x] = weight;
    // if undirected
    if (!directed) matrix[x][y] = weight;
}

int Graph_m::get_size(void) {
    return size;
}

void Graph_m::print(void) {
    int n = size;
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            std::cout << matrix[i][j]<< "\t";
        }
        std::cout << std::endl;
    }
}
