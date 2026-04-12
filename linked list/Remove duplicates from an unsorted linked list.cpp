/*
The structure of linked list is the following

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution {
  public:
    Node *removeDuplicates(Node *head) {
        
        unordered_set<int> set;
        
        Node* curr = head;
        
        if(head == NULL) return head;
        else 
            set.insert(curr->data);
            
        while(curr != NULL && curr->next != NULL){
            
            if(set.find(curr->next->data) != set.end()){
                //same
                curr->next = curr->next->next;
            }
            else{
                // not same
                set.insert(curr->next->data);
                curr = curr->next;
            }
        }
        return head;
        
        
        
    }
};