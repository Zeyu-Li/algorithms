/*
* Binary tree implementation 
* Resource: https://gist.github.com/toboqus/def6a6915e4abd66e922
*/
#include <iostream>


// each node struct
template<typename T>
struct node {
    T value;

    node *lhs;
    node *rhs;
};

// binary tree class
template<class Type>
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
        void insert(Type value);

        // searches and returns the node
        node<Type> *search(Type value);
    protected:
        // root node
        node<Type> *root;

        // print helper funcs (overloads)
        void pre_order(node<Type> *leaf);
        void in_order(node<Type> *leaf);
        void post_order(node<Type> *leaf);

        // destroyer helper func
        void delete_node(node<Type> *some_node);

        // overloading insert of adding root to somewhere in the tree
        void insert(Type value, node<Type> *leaf);
        
        // searches helper func
        node<Type> *search(Type value, node<Type> *leaf);
};

// constructor and destructor
template<class Type>
Binary_tree<Type>::Binary_tree() {
    root = nullptr;
}
template<class Type>
Binary_tree<Type>::~Binary_tree() {
    delete_node(root);
}

// inserts
template<class Type>
void Binary_tree<Type>::insert(Type value) {
    if (root != nullptr) {
        // insert a key at root
        insert(value, root);
    } else {
        // inserting a new node
        root = new node<Type>;
        root->lhs = nullptr;
        root->rhs = nullptr;
        root->value = value;
    }
}
template<class Type>
void Binary_tree<Type>::insert(Type value, node<Type> *leaf) {
    if (value < leaf->value) {
        // goto left subtree

        // if non trivial, keep recursively finding the subtree
        if (leaf->lhs != nullptr) {
            insert(value, leaf->lhs);
        } else {
            // inserting a new node
            leaf->lhs = new node<Type>;
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
            leaf->rhs = new node<Type>;
            leaf->rhs->lhs = nullptr;
            leaf->rhs->rhs = nullptr;
            leaf->rhs->value = value;
        }
    }
}

// deletes subtrees
template<class Type>
void Binary_tree<Type>::delete_node(node<Type> *some_node) {
    if (some_node != nullptr) {
        // recursive delete on both rhs and lhs
        delete_node(some_node->lhs);
        delete_node(some_node->rhs);
        // delete self root
        delete some_node;
    }
}

// prints
template<class Type>
void Binary_tree<Type>::pre_order() {
	pre_order(root);
	std::cout << std::endl;
}
template<class Type>
void Binary_tree<Type>::pre_order(node<Type> *leaf) {
	if (leaf != nullptr) {
        std::cout << leaf->value << " ";
        pre_order(leaf->lhs);
        pre_order(leaf->rhs);
    }
}
template<class Type>
void Binary_tree<Type>::in_order() {
	in_order(root);
	std::cout << std::endl;
}
template<class Type>
void Binary_tree<Type>::in_order(node<Type> *leaf) {
	if (leaf != nullptr) {
        // print lhs then rhs
        in_order(leaf->lhs);
        std::cout << leaf->value << " ";
        in_order(leaf->rhs);
    }
}
template<class Type>
void Binary_tree<Type>::post_order() {
	post_order(root);
	std::cout << std::endl;
}
template<class Type>
void Binary_tree<Type>::post_order(node<Type> *leaf) {
	if (leaf != nullptr) {
        post_order(leaf->lhs);
        post_order(leaf->rhs);
        std::cout << leaf->value << " ";
    }
}

// searches
template<class Type>
node<Type> *Binary_tree<Type>::search(Type value) {
    // search in root
    return search(value, root);
}
template<class Type>
node<Type> *Binary_tree<Type>::search(Type value, node<Type> *leaf) {
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
