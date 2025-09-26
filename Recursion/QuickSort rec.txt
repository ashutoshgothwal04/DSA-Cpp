
#include <iostream>
using namespace std;

int partition(int arr[], int s, int e) {
	int pivot= arr[s];
	int cnt =0;

	for(int i=s+1; i<=e; i++) {
		if(arr[i] <= pivot) {
			cnt++;
		}
	}

	// place pivot at right(dir) position
	int pivotIndex = s+cnt;
	swap(arr[pivotIndex], arr[s]);

	int i=s, j=e;
	while(i < pivotIndex && j > pivotIndex) {
		while(arr[i] <= pivot) i++;
		while(arr[j] > pivot) j--;

		if(i < pivotIndex && j > pivotIndex) {
			swap(arr[i++], arr[j--]);
		}
	}

	return pivotIndex;
}

void QuickSort(int arr[],int s, int e ) {
// base case
	if(s>=e) return;

// partition krege
	int p = partition(arr, s, e);

// left partition
	QuickSort(arr, s, p-1);

// right partition
	QuickSort(arr, p+1, e);
}

int main() {

	int arr[5] = {8,2,9,4,0};
	int n = 5;

	QuickSort(arr, 0, n-1);
	for(int val : arr) {
		cout << val << " ";
	}

	return 0;
}
