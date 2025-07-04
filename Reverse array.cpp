#include <iostream>
using namespace std;

void Reverse(int arr[], int size){
    int start = 0;
    int end = size - 1;
    
    while(start <= end){
        swap(arr[start], arr[end]);
        
        start++;
        end--;
    }
}

void printingArr(int arr[], int size){
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[6] = {1, 8, -9, -4, 0, 6};
    int brr[5] = {9, 6, -2, 0, 4};
    
    printingArr(arr, 6);
    printingArr(brr, 5);
    
    Reverse(arr, 6); // Reverse arr correctly with size 6
    Reverse(brr, 5); // Reverse brr correctly with size 5
    
    cout << "Reversed arr: ";
    printingArr(arr, 6);
    
    cout << "Reversed brr: ";
    printingArr(brr, 5);
    
    return 0;
}
