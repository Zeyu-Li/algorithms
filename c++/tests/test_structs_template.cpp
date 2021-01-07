/* 
* Testing Template Structs
* Description: A test for all the classes
*/ 
#include <iostream>
#include "../structs/binary_tree_t.cpp"
#include "../structs/graph_t.cpp"
#include "../structs/matrix_graph_t.cpp"

using namespace std;

int main() {
    /* binary tree template */
    cout << "Binary tree:" << endl;
    Binary_tree<float> tree;

    // for best results, randomize inserts so the tree can be somewhat balanced
    tree.insert(10.6);
    tree.insert(5);
    tree.insert(11.9);
    tree.insert(47.3);
    tree.insert(-0.0);

    tree.pre_order();
    tree.in_order();
    tree.post_order();

    // node<float> *find = tree.search(10);
    // must set overload to public to do the thing below
    // tree->post_order(find);

    delete &tree;

    /* graph */
    cout << "Graph:" << endl;
    Graph<float> graph;

    graph.add_edge(2, 4, 10.5);
    graph.add_edge(4, 3);
    graph.print();

    /* matrix graph */
    cout << "Matrix graph:" << endl;
    Graph_m<float> graph_m(true, 5);
    // std::cout << graph.get_size();
    graph_m.add_edge(3,2);
    graph_m.add_edge(2,1, 2.5);

    graph_m.print();
    // std::cout << graph.matrix[1][1];

    return 0;
}
