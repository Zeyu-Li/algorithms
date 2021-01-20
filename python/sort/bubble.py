""" Bubble sort O(n^2) """

def bubbleSort(arr):
    # bubbles the largest number up

    # for all elements in array (skip first element)
    for i in range(len(arr)):
        for j in range(len(arr)-i-1):
            # swap elements if smaller
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
