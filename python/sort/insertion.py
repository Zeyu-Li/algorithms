""" Insertion sort O(n^2) """

def insertionSort(arr):
    # for all elements in array (skip first element)
    for i in range(1, len(arr)):
        # examining element
        key = arr[i]

        # start from the one below the current and move down the array
        j = i
        while j > 0 and key < arr[j-1]:
            # shift one down
            arr[j] = arr[j-1]
            j-=1
        arr[j] = key
