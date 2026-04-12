#include <bits/stdc++.h> 
int findMinimumCost(string str) {
    // odd case
    if(str.length()%2 == 1) return -1;

    stack<char> s;
    for(char ch : str){
      if(ch == '{'){
        s.push(ch);
      }else{ // we have closing brakets "}"
        if(!s.empty() && s.top() == '{'){
          s.pop();
        }else{
          s.push(ch);
        }
      }
    }

   // calculating ans 
   int a = 0, b = 0;
   while(!s.empty()){
    if(s.top() == '{') b++;
    else a++;
    s.pop();
   }
    int ans = (a+1)/2 + (b+1)/2;
    return ans;

}