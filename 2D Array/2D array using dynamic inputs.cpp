#include <stdio.h>
#include <iostream>
using namespace std;


int main() {
	int row;
	cout<<"row"<<endl;
	cin>> row;
	int col;
	cout<<"col"<<endl;
	cin>> col;


	// contructing 2D matrix
	int** arr = new int* [row];
	for(int i=0; i<row; i++) {
		arr[i] = new int[col];
	}


	// taking inputs
	for(int i=0; i<row; i++) {
		for(int j=0; j<col; j++) {
			cin>>arr[i][j];
		}
	}
	cout << endl;

	// taking output
	for(int i=0; i<row; i++) {
		for(int j=0; j<col; j++) {
			cout<<arr[i][j] << " ";
		}
		 cout << endl;  // breaking row for each new row 
	}

	// Optional: Deallocating memory
	for (int i = 0; i < row; i++) {
		delete[] arr[i];
	}
	delete[] arr;


	return 0;
}