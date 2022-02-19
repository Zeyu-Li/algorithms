'''
Sort Tests
'''
from typing import Callable
import sys, os
sys.path.insert(0, os.path.abspath('..'))

from sort.bubble import bubbleSort
from sort.insertion import insertionSort
from sort.merge import mergeSort
from sort.quick import quickSort
from sort.count import count_sort
from sort.radix import radix_sort

empty = []
_sorted = [1,2,3,4,5,6]
to_sort = [7,3,8,45,4,7568,67,88,46,67,4567,23,3]
sorted_list = [3, 3, 4, 7, 8, 23, 45, 46, 67, 67, 88, 4567, 7568]

def helper(sortFunc: Callable):
    copy1 = empty[:]
    copy2 = _sorted[:]
    copy3 = to_sort[:]
    sortFunc(copy1)
    sortFunc(copy2)
    sortFunc(copy3)
    assert empty == copy1, "empty sort not valid"
    assert copy2 == _sorted, "sorted not valid"
    assert copy3 == sorted_list, "sort not valid"

def helper2(sortFunc: Callable):
    copy1 = empty[:]
    copy2 = _sorted[:]
    copy3 = to_sort[:]
    assert empty == sortFunc(copy1), "empty sort not valid"
    assert sortFunc(copy2) == _sorted, "sorted not valid"
    assert sortFunc(copy3) == sorted_list, "sort not valid"

def main():
    print("Bubble")
    helper(bubbleSort)
    print("Insertion")
    helper(insertionSort)
    print("Quick")
    helper2(quickSort)
    print("Merge")
    helper2(mergeSort)
    print("Count")
    helper(count_sort)
    print("Radix")
    helper(radix_sort)

    print("All tests passed")
    return 0

if __name__ == "__main__":
    main()
