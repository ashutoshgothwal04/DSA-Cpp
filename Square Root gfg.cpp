class Solution {
  public:
    int floorSqrt(int n) {
        //* solution 1: find square root of number 
        
        // return sqrt(n);
        
        // ---------------------------------------------------
        
        //* solution 2: Start from 1 and square each 
        // number until the square exceeds the given number. 
        // The last number whose square is less than or equal 
        // to n is the answer.
        
        // int res = 1;
        // while(res*res <= n) res++;
        // return res-1;
        
        // ------------------------------------------------------
        
        //* sol 2:  binary search 
        
        int s = 1, e = n;
        int res = 1;
        
        while(s<=e){
            int mid = s+(e-s)/2;
            if(mid*mid <= n) {
                res=mid;
                s = mid+1;
            } else{
                e=mid-1;
            }
        }
        return res;
    }
};

















