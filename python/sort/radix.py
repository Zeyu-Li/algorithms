""" Radix sort - only sort with O(n) """
def count_sort(arr, exp):
    n = len(arr)

    output = [0 for _ in range(n)]
    count = [0 for _ in range(10)]

    # Store count of occurrences in count
    for i in range(0, n):
        index = arr[i] // exp
        count[index % 10] += 1

    # store count of each number
    for i in range(1, 10):
        count[i] += count[i - 1]

    # Build the output array
    i = n - 1
    while i >= 0:
        index = arr[i] // exp
        output[count[index % 10] - 1] = arr[i]
        count[index % 10] -= 1
        i -= 1

    for i in range(len(arr)):
        arr[i] = output[i]


def radix_sort(arr, bucket = 10):
    if (len(arr) == 0): return
    # see https://www.geeksforgeeks.org/radix-sort/?ref=lbp
    _max = max(arr)

    # for count sort for every digit
    exp = 1
    while _max / exp > 1:
        count_sort(arr, exp)
        exp *= bucket
