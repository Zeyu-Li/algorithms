#include <iostream>
#include <vector>

// help from https://github.com/DorianDepriester/adjacencyMatrix


template<class T>
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
        void resize(int);

        // setter (edge)
        void add_edge(int, int);
        // overloads when default weight is not 1
        void add_edge(int, int, T);

        // main matrix, therefore getter unnecessary
        std::vector<std::vector <T>> matrix;
    protected:
        int size;
        bool directed;
};

template<class T>
Graph_m<T>::Graph_m() {
    size=0;
    directed = true;
}
template<class T>
Graph_m<T>::Graph_m(bool direc) {
    size=0;
    directed = direc;
}
template<class T>
Graph_m<T>::Graph_m(int n) {
    directed = true;
    // resize
    size=0;
    resize(n);
    size=n;
}
template<class T>
Graph_m<T>::Graph_m(bool direc, int n) {
    directed = direc;
    // resize
    size=0;
    resize(n);
    size=n;
}
template<class T>
Graph_m<T>::~Graph_m() {
    size=0;
}

// resize
template<class T>
void Graph_m<T>::resize(int new_size) {
    if (new_size > size) {
        // enlarge the matrix
        for (int i = size; i<new_size; i++) {
            // add zero to each row
            // zeros for each row
            std::vector<T> bottom;
            for (int j = size; j<new_size; j++) {
                bottom.push_back(0);
            }
            matrix.push_back(bottom);
        }
    }
}

// add edge row then column
template<class T>
void Graph_m<T>::add_edge(int y, int x) {
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
template<class T>
void Graph_m<T>::add_edge(int y, int x, T weight) {
    // sets size as the max of x or y
    int max = x > y ? x : y;
    if (max>size) {
        size = max;
    }
    matrix[y][x] = weight;
    // if undirected
    if (!directed) matrix[x][y] = weight;
}

template<class T>
int Graph_m<T>::get_size(void) {
    return size;
}

template<class T>
void Graph_m<T>::print(void) {
    int n = size;
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            std::cout << matrix[i][j]<< "\t";
        }
        std::cout << std::endl;
    }
}
