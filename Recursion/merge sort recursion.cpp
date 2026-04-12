#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int st, int mid, int end) {
    vector<int> temp;
    int i = st;
    int j = mid+1;

    // Merge elements from both halves into temp
    while(i <= mid && j <= end) {
        if(arr[i] < arr[j]) {
            temp.push_back(arr[i]);
            i++;
        }
        else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    // Copy any remaining elements from the left half
    while(i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }
    // Copy any remaining elements from the right half
    while(j <= end) {
        temp.push_back(arr[j]);
        j++;
    }

    // Copy sorted elements back to the original array
    for(int idx = 0; idx < temp.size(); idx++) {
        arr[st + idx] = temp[idx];
    }
}


void mergeSort(vector<int>& arr, int st, int end) {

	if(st<end) {
		int mid = st+(end-st)/2;

		mergeSort(arr, st, mid); // left part of array
		mergeSort(arr, mid+1, end); // right part of array

		merge(arr, st, mid, end);
	}
}

int main() { 

	vector<int> arr = {6,0,9,1,4};

	mergeSort(arr, 0, arr.size()-1);
	
	for(int nums : arr){
	     cout << nums << " ";
	}

	return 0;
}