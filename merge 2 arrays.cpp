#include <iostream>
#include <vector>
using namespace std;

void merge(int arr1[], int n, int arr2[], int m, vector<int>& arr3) {
	int i = 0, j = 0;

	while(i < n && j < m) {
		if(arr1[i] < arr2[j]) {
			arr3.push_back(arr1[i++]);
		} else {
			arr3.push_back(arr2[j++]);
		}
	}

	while(i < n) {
		arr3.push_back(arr1[i++]);
	}

	while(j < m) {
		arr3.push_back(arr2[j++]);
	}
}

void print(const vector<int>& arr3) {
	for(int i = 0; i < arr3.size(); i++) {
		cout << arr3[i] << " ";
	}
	cout << endl;
}

int main()
{
	int arr1[5] = {1, 3, 5, 7, 9};
	int arr2[3] = {2, 4, 6};
	vector<int> arr3;

	merge(arr1, 5, arr2, 3, arr3);
	print(arr3);

	return 0;
}
