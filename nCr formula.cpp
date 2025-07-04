#include <iostream>
#include <math.h>
using namespace std;

int factorial(int n){
    
    int fact = 1;
    for(int i=1; i<=n; i++){
        fact = fact * i;
    }
    return fact;
}



int nCr(int n, int r){
    
    int upper = factorial(n);
    int lower = factorial(r) * factorial(n - r);
    
    return upper/lower;
    
}




int main()
{
      
    int n, r;
    
    cin >> n >> r;
    
    cout << "answer is: " << nCr(n,r) << endl;
      
}