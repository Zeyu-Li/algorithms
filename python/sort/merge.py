""" Merge sort O(nlogn) """

def merge(left, right):
    i = j = 0
    result = []

    # merging left and right mantaining sorted order
    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            result.append(left[i])
            i+=1
        else:
            result.append(right[j])
            j+=1

    # append the rest of the subarray into result
    result += left[i:]
    result += right[j:]
    return result

def mergeSort(arr):
    if len(arr) <= 1:
        return arr
    
    mid = len(arr)//2

    # have a left and right hand side
    # sort left and right sublist
    left = mergeSort(arr[:mid])
    right = mergeSort(arr[mid:])

    return merge(left, right)