'''
Struct tests
'''
import sys, os
sys.path.insert(0, os.path.abspath('..'))

from structs.SinglyLinkedList import SLinkedList
from structs.DoublyLinkedList import DLinkedList
from structs.BoundedQueue import Queue 
from structs.CircularQueues import CircularQueue
from structs.Stack import Stack

test1 = []
test2 = [1,2,3,4,5,6]
test3 = [6,6,4,2,1,3,5,6,3,7,8,5,3,3,67,4,8,4,67,43543,456,456,4]

def main():
    print("Singly Linked List")
    newList1 = SLinkedList()
    for item in test1:
        newList1.add(item)
    assert str(newList1) == '', "Not empty array!"

    for item in test2:
        newList1.append(item)
    assert str(newList1) == '1->2->3->4->5->6->', "Not correct linked list!"

    for item in test2:
        newList1.pop()
    assert str(newList1) == '', "Not empty array!"

    for item in test3:
        newList1.add(item)

    assert str(newList1) == '4->456->456->43543->67->4->8->4->67->3->3->5->8->7->3->6->5->3->1->2->4->6->6->', "Not correct linked list!"

    newList2 = SLinkedList()
    for item in test2:
        newList2.append(item)

    newList2.insert(2,2)
    newList2.remove(2)
    # print(newList2)
    assert str(newList2) == '1->2->3->4->5->6->', "Not correct linked list!"

    print("Doubly Linked List")
    newList1 = DLinkedList()
    for item in test1:
        newList1.add(item)
    assert str(newList1) == '', "Not empty array!"

    for item in test2:
        newList1.append(item)
    assert str(newList1) == '1 2 3 4 5 6', "Not correct linked list!"

    for item in test2:
        newList1.pop()
    assert str(newList1) == '', "Not empty array!"

    for item in test3:
        newList1.add(item)

    assert str(newList1) == '4 456 456 43543 67 4 8 4 67 3 3 5 8 7 3 6 5 3 1 2 4 6 6', "Not correct linked list!"

    newList2 = DLinkedList()
    for item in test2:
        newList2.append(item)

    newList2.insert(2,2)
    newList2.remove(2)
    # print(newList2)
    assert str(newList2) == '1 2 3 4 5 6', "Not correct linked list!"

    print("Bounded Queue")
    newList1 = Queue()
    newList2 = Queue()
    for item in test2:
        newList1.enqueue(item)
    newList2.define(list(reversed(test2)))
    assert str(newList1) == str(newList2), "not same list"
    assert newList1.peek() == 1, "not a queue"

    print("Circular Queue")
    newList1 = CircularQueue(6)
    newList2 = CircularQueue(6)
    for item in test2:
        newList1.enqueue(item)
    assert newList1.peek() == 1, "not a queue"
    for item in test2:
        newList1.dequeue()
    assert newList1.size() == 0, "non empty circular queue"

    print("Stacks")
    newList1 = Stack()
    for item in test2:
        newList1.push(item)
    newList1.clear()
    assert newList1.isEmpty(), "stack is not empty"


    print("All tests passed")
    return 0

if __name__ == "__main__":
    main()
