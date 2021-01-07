/* Heaps */ 
#include <iostream>
#include <algorithm>
#include <vector>

class Min_heap {
    public:
        Min_heap();

        void push_back(int);
        // push back array of ints
        void push_back(int, int []);
        void pop_back();

        // returns value given index
        int get_value(int);
        
        // get size
        int get_size();

        // print
        void print();
    protected:
        int size;
        std::vector<int> heap;
};

Min_heap::Min_heap() {
    size = 0;
}

void Min_heap::push_back(int value) {
    heap.push_back(value);
    if (heap.size() == 1) {
        std::make_heap(heap.begin(), heap.end());
    } else {
        std::push_heap(heap.begin(), heap.end());
    }
}
void Min_heap::push_back(int size, int arr[]) {
    for (int i = 0; i < size; i++) {
        heap.push_back(arr[i]);
    }
    std::make_heap(heap.begin(), heap.end());
}
void Min_heap::pop_back() {
    // if heap is zero, then cannot pop
    if (heap.size() == 0) return;
    // alternately
    // throw 1;
    std::pop_heap(heap.begin(), heap.end());
    heap.pop_back();
}

int Min_heap::get_value(int index) {
    return heap[index];
}
int Min_heap::get_size() {
    return size;
}

// print
void Min_heap::print() {
    for (unsigned i=0; i<heap.size(); i++) std::cout << heap[i] << ' ' ;
    std::cout << std::endl;
}
