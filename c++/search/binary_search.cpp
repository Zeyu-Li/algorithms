/* Binary Search */ 
#include <vector>

// returns index of x in array (must be vector), -1 if x is not found in array
int binary_search(std::vector<int>&array, int x) {
    int low = array[0];
    int high = array[array.size()];
    while (low <= high) {
        int mid = low + (high-low) / 2;

        if (array[mid] > x) {
            high = mid - 1;
        } else if (array[mid] < x) {
            low = mid + 1;
        } else {
            return mid;
        }
    }

    return -1;
}
