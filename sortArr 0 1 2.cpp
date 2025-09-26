#include <iostream>
using namespace std;

void sortArray(int arr[], int n) {
    int i = 0, j = 0, k = n - 1;  // Initialize the three pointers

    while (j <= k) {
        if (arr[j] == 0) {
            // Swap arr[i] and arr[j] for 0 placement
            swap(arr[i], arr[j]);
            i++;  // Increment i to move to the next position for 0
            j++;  // Increment j to move to the next element
        } else if (arr[j] == 1) {
            // No action needed for 1, just move j forward
            j++;
        } else {
            // Swap arr[j] and arr[k] for 2 placement
            swap(arr[j], arr[k]);
            k--;  // Decrement k to move to the previous position for 2
        }
    }
}

int main() {
    int arr[9] = {0, 1, 0, 2, 0, 1, 2, 1, 2};
    int n = 9;
    
    sortArray(arr, n);
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    return 0;
}
