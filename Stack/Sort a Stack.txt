#include <bits/stdc++.h> 

void solve(stack<int> &stack, int num){
    if(stack.empty() || stack.top() < num){
        stack.push(num);
        return;
    }

    int top = stack.top();
    stack.pop();
    solve(stack, num); // rec call
    stack.push(top); 
}

void sortStack(stack<int> &stack){
	// base case
    if(stack.empty()) return ;

    int num = stack.top();
    stack.pop();
    sortStack(stack); // rec call
    solve(stack, num); 
}