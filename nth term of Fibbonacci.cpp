#include <iostream>
#include <math.h>
using namespace std;

int fibonacci(int n){
    int a = 0;
    int b = 1;
    int fib = 0;
   
    
    cout << a << " "<< b<<" ";
    for (int i=0;i<n;i++){
        fib = a+b;
        cout << fib << " ";
        
        a = b;
        b = fib;
        
    }
    cout << endl;
     return b;
}

int main(){
    int n;
    cin >> n;

    cout << "The "<<n<<"th term of the series is "<< fibonacci(n)<<endl;
    
    return 0;
}