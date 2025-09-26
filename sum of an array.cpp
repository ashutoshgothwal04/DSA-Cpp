#include <iostream>
#include <climits>
using namespace std;


int sum(int arr[], int size){
    
    int cal = 0;
    
    for(int i = 0; i < size; i++){
        cin >> arr[i];
        cal+= arr[i];
    }
    
    return cal;
}


int main()
{
    int size ;
    cout << "Enter the size of the array (1 to 10): ";
    cin >> size ;
    
    if (size > 10) {
        cout << "Size cannot exceed 10. Please enter a size between 1 and 10." << endl;
        return 1;  // Exit with an error
        }

    int arr[10];
    
    cout << "Enter " << size << " elements for the array: ";
    int answer = sum(arr, size);
    
    cout << "The sum of the array elements is: " << answer << endl;
	return 0;
}