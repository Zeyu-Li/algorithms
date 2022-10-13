# Quick Algorithms or Formulas

[![Testing](https://github.com/Zeyu-Li/algorithms/actions/workflows/main.yml/badge.svg)](https://github.com/Zeyu-Li/algorithms/actions/workflows/main.yml)

## About

This is a collection of algorithms, formulas, or  written in different programing languages

## ADT

### Python

* Stack [O(1) constant]
* Bounded Queues [O(n) linear time]
* Circular Queues [O(1) constant]

The next two have a node (SLinkedListNode or DLinkedListNode) and the implementation (SLinkedList or DLinkedList)

* Singly Linked List [O(n) linear time] 
* Doubly Linked List [O(n) linear time] 



### C++

**Included in STL**

* Stack
* Queue
* Priority Queue
* Vectors
* Lists (similar to Vectors)
* Sets
* Heaps
* Sorting O(nlog(n))

**Mine**

* Binary Tree (has template class)
* Hash Table
* Graphs
  * Matrix representation (has template class)
  * List/Hash-like table representation (has template class)
  * List of edges with weights
* Heaps



## Algorithms

### Python

* GCD (greatest common denominator) by Euclidean algorithm
* LCM (least common multiple) uses GCD
* Pi Approximator via Monte Carlo
* Matrix Multiplication O(n^3)
* Strassen's Matrix Multiplication ~O(n^2.81) (less precise than the one above)
* Power set ~O(n * 2^n) (Generates a power set given iterator)

### C++

* GCD via Euclidean algorithm
* LCM (least common multiple) uses GCD
* BFS - Breath first search (+ shortest path) O(V+E)
* DFS - Depth first search O(V+E)
* Dijkstra's Algorithm - Shortest path O(V^2)
* A Star Search - Shortest path O(V^2)
* Bellman-Ford - Shortest path (dp) O(E*V)
* Floyd-Warshall - Shortest path for all pairs of points O(V^3)
* Kruskal's Algorithm - Minimum spanning tree O(E log E)
* Prim's Algorithm - Minimum spanning tree O(V^2)
* Quick Square Root from [Quake III](https://www.youtube.com/watch?v=p8u_k2LIZyo&ab_channel=Nemean)

### Go

* Is prime

### TypeScript

* Is prime

## Sorting

### Python

* Insertion O(n^2)
* Bubble O(n^2)
* Merge O(nlogn)
* Quick O(nlogn)
* Count O(n+k)
* Radix O(n)

## Concepts

### Greedy

Take the best in current case and continue for all cases (don't look back)

### Divide and Conquer

Divides problems into many subproblems that can be tackled (usually in similar ways)

### Dynamic Programming

Keep a table or array of calculated values such that items in table or array need to be calculated only once

### Hash Tables/Maps

Very efficient data structures that can speed up search, push and many others. Most of the time, modulus will be used as the hash function. In Python, dictionaries are hash maps and are really useful. JavaScript has objects that can also act like hash tables! 

### Randomness

Randomness in so algorithms can improve running time, especially if you are parallelize it such that the randomness can help you get the answer with the fastest sub-processes



## How to Use

### Python

For MacOS or Linux:

```shell
python3 name_of_program.py
```

For Windows:

```powershell
py name_of_program.py
```

### C++

Needs to be complied (recommended gcc)

### Usage

Can be copied and pasted directly to the file or drag in the file and be include with `#include "NameOfFile.cpp"` header



## Licence

[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](https://opensource.org/licenses/MIT) 

The rules for copy and distributing this project licence are 
outlined in the licence.txt file.

This project is under an MIT licence 