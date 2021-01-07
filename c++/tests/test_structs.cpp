/* 
* Testing Structs
* Description: A test for all the classes
*/ 
#include <iostream>
#include "../structs/binary_tree.cpp"
#include "../structs/heap.cpp"
#include "../structs/hash_table.cpp"
#include "../structs/graph.cpp"
#include "../structs/list_graph.cpp"
#include "../structs/matrix_graph.cpp"

using namespace std;

int main() {
    /* binary tree */
    cout << "Binary tree:" << endl;
    Binary_tree *tree = new Binary_tree();

    // for best results, randomize inserts so the tree can be somewhat balanced
    tree->insert(10);
    tree->insert(5);
    tree->insert(11);
    tree->insert(47);
    tree->insert(0);

    tree->pre_order();
    tree->in_order();
    tree->post_order();

    node *find = tree->search(10);
    // must set overload to public to do the thing below
    // tree->post_order(find);

    delete tree;

    /* heap (very rudimentary) */
    cout << "Heap:" << endl;
    int arr[] = {1,5,7,3,68,4};
    Min_heap heap;

    heap.push_back(sizeof(arr)/sizeof(arr[0]), arr);
    heap.push_back(4);
    heap.pop_back();
    heap.print();

    /* hash table */
    cout << "Hash table:" << endl;
    Hash_table table(3);

    int a[] = {2,5,7,3,7,3,5,2,6,3};
    int size = sizeof(a)/sizeof(a[0]);

    table.insert_items(size, a);
    table.delete_item(7);

    // prints
    table.print();

    /* graph */
    cout << "Graph:" << endl;
    Graph graph;

    graph.add_edge(2, 4, 10);
    graph.add_edge(4,3);
    graph.print();

    /* list graph */
    cout << "List graph:" << endl;
    Graph_l graph_l(false, 4);
    graph_l.add_edge(1,3);
    graph_l.add_edge(0,2);
    graph_l.add_edge(0,1);
    graph_l.delete_edge(0,2);
    graph_l.print();
    graph_l.add_edge(0,2);
    graph_l.print_edges(0);

    /* matrix graph */
    cout << "Matrix graph:" << endl;
    Graph_m graph_m(false, 5);
    // std::cout << graph.get_size();
    graph_m.add_edge(3,2);
    graph_m.add_edge(2,1, 5);

    graph_m.print();
    // std::cout << graph.matrix[1][1];

    return 0;
}
