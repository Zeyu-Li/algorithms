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
        // pre-order = Root-Left-Right
        void pre_order();
        // in order = Left-Root-Right
        void in_order();
        // post order = Left-Right-Root
        void post_order();

        // general insert of value (int)
        void insert(int value);

        // searches and returns the node
        node *search(int value);
    private:
        // root node
        node *root;

        // print helper funcs (overloads)
        void pre_order(node *leaf);
        void in_order(node *leaf);
        void post_order(node *leaf);

        // destroyer helper func
        void delete_node(node *some_node);

        // overloading insert of adding root to somewhere in the tree
        void insert(int value, node *leaf);
        
        // searches helper func
        node *search(int value, node *leaf);
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
void Binary_tree::pre_order() {
	pre_order(root);
	std::cout << std::endl;
}
void Binary_tree::pre_order(node *leaf) {
	if (leaf != nullptr) {
        std::cout << leaf->value << " ";
        pre_order(leaf->lhs);
        pre_order(leaf->rhs);
    }
}
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
void Binary_tree::post_order() {
	post_order(root);
	std::cout << std::endl;
}
void Binary_tree::post_order(node *leaf) {
	if (leaf != nullptr) {
        post_order(leaf->lhs);
        post_order(leaf->rhs);
        std::cout << leaf->value << " ";
    }
}

// searches
node *Binary_tree::search(int value) {
    // search in root
    return search(value, root);
}
node *Binary_tree::search(int value, node *leaf) {
    // if not found, returns null ptr

    // search in root
    if (leaf == nullptr) {
        return nullptr;
    } else {
        if (leaf->value == value) {
            return leaf;
        } else if (leaf->value < value) {
            // goto right sub tree
            return search(value, leaf->rhs);
        } else {
            return search(value, leaf->lhs);
        }
        
    }
    
    return search(value, root);
}
