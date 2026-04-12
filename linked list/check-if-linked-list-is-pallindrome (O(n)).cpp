/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
       data = x;
       next = NULL;
    }
};
*/
#include <vector>

class Solution {
  public:
   
    bool check(vector<int> arr){
      int s = 0, e = arr.size()-1;
        while(s <= e){
            if(arr[s] != arr[e]) return false;
            s++;
            e--;
        }
        return true;
    }
  
    bool isPalindrome(Node *head) {
        
        vector<int> arr;
        Node* temp = head;
        
        while(temp != NULL){
            arr.push_back(temp->data);
            temp = temp -> next;
        }
        return check(arr);
    }
};