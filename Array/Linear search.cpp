#include <iostream>
using namespace std;

bool search(int arr[], int size, int key){
    
    for(int i=0; i<size; i++){
        
        if(arr[i] == key){
            return 1;
        }
        
    }
    return 0;
    
}


int main()
{
    
    int arr[10] = {1,8,-9,-4,0,6,7,3,-1,5};
    
    int key;
    cout << " Enter key value: ";
    cin>>key;
    
    bool isfound = search(arr, 10, key);
    
    if(isfound){
        cout << "given value "<< key << " is PRESENT in array"<<endl;
    }else{
      cout << "given value "<< key << " is NOT in array"<<endl; 
    }
   
    return 0;
}