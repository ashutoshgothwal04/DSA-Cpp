#include <iostream>
using namespace std;


int BinarySearch(int arr[], int size, int key) {

	int start = 0, end = size-1;

	int mid = start + (end - start) / 2;

	while(start <= end) {

		if(arr[mid] == key) return mid;

		if(arr[mid] < key) {
			start = mid + 1;
		} else {
			end = mid - 1;
		}
		mid = start + (end - start) / 2;
	}
	return -1;
}


int main()
{

	int even[6] = {6,8,9,12,14,18};
//   int odd[5] = {8,15,20,29,55};

	int index = BinarySearch(even, 6, 8);

	cout << "index of 8 is: " << index<<endl;


	return 0;
}