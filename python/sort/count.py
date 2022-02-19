""" Count sort O(n+k) where k is the range of input """
def count_sort(arr):
    if (len(arr) == 0): return []
    # see https://www.geeksforgeeks.org/counting-sort/
    _max = max(arr)
    _min = min(arr)
    _range = _max - _min + 1
    # probably better to do this in a functional language
    counts = [0 for _ in range(_range)]
    output = [0 for _ in range(len(arr))]

    # store count of each number
    for i in range(len(arr)):
        counts[arr[i]-_min] += 1
    
    # runing sum fold
    for i in range(1, len(counts)):
        counts[i] += counts[i-1]

    # main step
    for i in range(len(arr)-1, -1, -1):
        output[counts[arr[i] - _min] - 1] = arr[i]
        counts[arr[i] - _min] -= 1

    for i in range(0, len(arr)):
        arr[i] = output[i]

