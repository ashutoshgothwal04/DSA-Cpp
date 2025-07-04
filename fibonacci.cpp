#include <iostream>
using namespace std;

int main(){
    
    int n = 10;
    
    int a= 0;
    int b= 1;
    cout << a << " "<< b<< " ";
    for(int i=0;i<=n;i++){
        int fib = a+b;
        
        cout << fib<< " ";
        a = b;
        b= fib;
    }
    
    return 0;
}