/* 
* Hash Table by Andrew Li
*/ 
#include <iostream>
#include <list>


class Hash_table {
    private: 
        // number of rows
        int size;
        // container
        std::list<int> *table;

        // hash function is a simple modulo
        int hashing(int num) {
            return num % size;
        }

    protected:
        // contructor, n is number of rows
        Hash_table(int n);
        // destructor
        ~Hash_table();

        void insert_item(int item);
        // inserting an array of numbers given size and array
        void insert_items(int n, int arr[]);
        // NOTE: only deletes first occurrence of item
        void delete_item(int item);

        // prints
        void print();

        // getter
        int get_size();
};
// contructor
Hash_table::Hash_table(int n) {
    size = n;
    table = new std::list<int>[n];
}
Hash_table::~Hash_table() {
    delete[] table;
}
// insert item via hash func
void Hash_table::insert_item(int item) {
    table[hashing(item)].push_back(item);
}
// overloads with multiple items
void Hash_table::insert_items(int items, int arr[]) {
    for (int i = 0; i<items; i++) {
        table[hashing(arr[i])].push_back(arr[i]);
    }
}
// remove item via hash func
void Hash_table::delete_item(int item) {
    int row = hashing(item);

    // iterate through table by rows
    std::list<int> :: iterator i;
    for (i = table[row].begin(); i != table[row].end(); i++) {
        if (*i == item) break;
    }

    // if it exists in the table, delete it (possible to fit this in the previous for loop)
    if (i != table[row].end()) table[row].erase(i);
}

// print
void Hash_table::print() {
    for (int i = 0; i<size; i++) {
        std::cout << i;
        for (auto item: table[i]) {
            std::cout << " -> " << item;
        }
        std::cout << std::endl;
    }
}

int Hash_table::get_size() {
    return size;
}
