""" Quick sort O(nlogn) """

# returns sorted array (not as space efficient as in array quick sort)
def quickSort(arr):
    # return if trivial cases
    if len(arr) <= 1:
        return arr
    
    # pivot
    pivot = arr[0]
    i = 0
    # for all elements in array
    for j in range(len(arr) - 1):
        # swap to end if larger than pivot 
        if arr[j+1] < pivot:
            # swap
            arr[j+1], arr[i+1] = arr[i+1], arr[j+1]
            i+=1

    # swap pivot
    arr[0], arr[i] = arr[i], arr[0]
    left = quickSort(arr[:i])
    right = quickSort(arr[i+1:])
    # add pivot back and return the whole subarray
    left.append(arr[i])

    return left + right
