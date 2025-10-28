#include <bits/stdc++.h>
using namespace std;

// reverse stack characters

stack<char> s;

int main() {
	string ch = "lucky";
	for(char val : ch){
	    s.push(val);
	}
	
	string ans = "";
	
	while(!s.empty()){
	   char top =  s.top();
	   ans.push_back(top);
	   s.pop();
	}
	   cout<< "reverse stack elements  "<< ans << endl;
         return 0;
}

