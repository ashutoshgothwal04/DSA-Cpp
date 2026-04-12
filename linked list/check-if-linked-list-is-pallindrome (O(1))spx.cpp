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


// algo:-
/*
    find mid {
        slow ko 1 aage badhao 
        fast ko 2 aage badhao 
    }
    revese mid->next{
        3 pointer approach :
            prev, curr, next
    }
    compare with starting and mid->next
*/

class Solution {
  public:
  
    Node* findMid(Node* head){
        Node* slow = head;
        Node* fast = head -> next;
        
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    Node* reverse(Node* head){
        
        
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
    
    bool isPalindrome(Node *head) {
        
        if (head == NULL || head->next == NULL) return true; 
        Node* curr = head;
        
        Node* mid = findMid(head);
        
        // reverse LL
        Node* rev = mid -> next;
        mid -> next = reverse(rev);
        
        // compare
        Node* MidKaNext = mid->next;
        while(MidKaNext != NULL){
            if(curr->data != MidKaNext->data){
                return false;
            }
            curr = curr ->next;
            MidKaNext = MidKaNext-> next;
        }
        return true;
    }
};



























