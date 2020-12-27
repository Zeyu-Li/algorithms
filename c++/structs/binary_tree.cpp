/*
* Binary tree implementation 
* Resource: https://gist.github.com/toboqus/def6a6915e4abd66e922
*/
#include <iostream>


// each node struct
// can change it's value(s) below such that 
// the node can encapsulate the data set
struct node {
    int value;

    node *lhs;
    node *rhs;
};

// binary tree class
class Binary_tree {
    public:
        // inits binary tree
        Binary_tree();
        ~Binary_tree();

        // prints (from root)
        void in_order();

        // general insert of value (int)
        void insert(int value);
    private:
        // root node
        node *root;

        // print helper funcs (overloads)
        void in_order(node *leaf);

        // destroyer helper func
        void delete_node(node *some_node);

        // overloading insert of adding root to somewhere in the tree
        void insert(int value, node *leaf);
};

// constructor and destructor
Binary_tree::Binary_tree() {
    root = nullptr;
}
Binary_tree::~Binary_tree() {
    delete_node(root);
}

// inserts
void Binary_tree::insert(int value) {
    if (root != nullptr) {
        // insert a key at root
        insert(value, root);
    } else {
        // inserting a new node
        root = new node;
        root->lhs = nullptr;
        root->rhs = nullptr;
        root->value = value;
    }
}
void Binary_tree::insert(int value, node *leaf) {
    if (value < leaf->value) {
        // goto left subtree

        // if non trivial, keep recursively finding the subtree
        if (leaf->lhs != nullptr) {
            insert(value, leaf->lhs);
        } else {
            // inserting a new node
            leaf->lhs = new node;
            leaf->lhs->lhs = nullptr;
            leaf->lhs->rhs = nullptr;
            leaf->lhs->value = value;
        }
    } else {
        // goto right subtree

        // if non trivial, keep recursively finding the subtree
        if (leaf->rhs != nullptr) {
            insert(value, leaf->rhs);
        } else {
            // inserting a new node
            leaf->rhs = new node;
            leaf->rhs->lhs = nullptr;
            leaf->rhs->rhs = nullptr;
            leaf->rhs->value = value;
        }
    }
}

// deletes subtrees
void Binary_tree::delete_node(node *some_node) {
    if (some_node != nullptr) {
        // recursive delete on both rhs and lhs
        delete_node(some_node->lhs);
        delete_node(some_node->rhs);
        // delete self root
        delete some_node;
    }
}

// prints
void Binary_tree::in_order() {
	in_order(root);
	std::cout << std::endl;
}
void Binary_tree::in_order(node *leaf) {
	if (leaf != nullptr) {
        // print lhs then rhs
        in_order(leaf->lhs);
        std::cout << leaf->value << " ";
        in_order(leaf->rhs);
    }
}

int main(int argc, char const *argv[])
{
    Binary_tree *tree = new Binary_tree();

    // for best results, randomize inserts so the tree can be somewhat balanced
    tree->insert(10);
    tree->insert(5);
    tree->insert(11);
    tree->insert(47);
    tree->insert(0);

    tree->in_order();

    delete tree;

    return 0;
}
