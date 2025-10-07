#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    //constrcutor
    Node(int d) {
        this->data = d;
        this->next = NULL;
    }

   ~Node() {
    cout << " memory is free for node with data " << this->data << endl;
}


};

void insertNode(Node* &tail, int element, int d){
  
  // empty list
  if(tail== NULL){
    Node* newNode=new Node(d);
    tail= newNode;
    newNode->next= newNode;
  }
  else{  // assuming that the element is present in the list
  
  Node* curr = tail;
  
  while(curr->data != element){
    curr = curr->next;
    if(curr == tail) {  // came back to start
        cout << "Element " << element << " not found!" << endl;
        return;
    }
  }
  
  // element is found
  Node* temp = new Node(d);
  temp -> next = curr-> next;
  curr->next= temp;
  }
}

void print(Node* tail){
  
   if(tail == NULL) {
        cout << "List is empty" << endl;
        return;
    }
  
  Node* temp = tail;
  
  //empty list
    if(tail == NULL) {
        cout << "List is Empty "<< endl;
        return ;
    }
    
   do {
        cout << temp->data << " ";
        temp = temp->next;  // use temp, not tail
    } while(temp != tail);
    
    
    cout << endl;
}


void deleteNode(Node* &tail, int value) {

    //empty list
    if(tail == NULL) {
        cout << " List is empty, please check again" << endl;
        return;
    }
    else{
        //non-empty

        //assuming that "value" is present in the Linked List
        Node* prev = tail;
        Node* curr = prev -> next;

        while(curr -> data != value) {
            prev = curr;
            curr = curr -> next;
        }

        prev -> next = curr -> next;

        //1 Node Linked List
        if(curr == prev) {
            tail = NULL;
        }

        //>=2 Node linked list
        else if(tail == curr ) {
            tail = prev;
        }

        curr -> next = NULL;
        delete curr;
    }
}

bool isCircularLL(Node* head){
    Node* temp = head->next;
    
    // empty list 
    if(head == NULL) return true;
    
    while(head!=NULL && temp != head){
      temp = temp->next;
    } 
    
    if(temp = head) return true;
     
     return false;
}




int main() {
    Node* tail = NULL;
    
    insertNode(tail, 5, 3);   // empty list → just insert 3
    print(tail);

    insertNode(tail, 3, 10);  // insert 10 after 3
    print(tail);

   /*
   
    insertNode(tail, 10, 20); // insert 20 after 10
    print(tail);

    insertNode(tail, 3, 4);  // insert 15 after 3
    print(tail);
    
    deleteNode(tail, 20);
    print(tail);
    
   */
   
   if(isCircularLL(tail)){
     cout << "LL is true "<< endl;
   }else{
     cout<< "not circular LL";
   }
    
    return 0;
}