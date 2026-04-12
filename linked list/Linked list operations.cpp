#include<iostream>
#include<map>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    //constructor
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
    
    // destructor
    ~Node() {
        int value = this->data;
        // memory free
        if(this->next != NULL){
            delete next;
            this-> next = NULL;
        }
        cout<< "memory is free for node with data "<< value<<endl;
    }
    
};

void insertAtHead(Node* &head, int d) {

    // new node create
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d) {
    
     // new node create
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = tail-> next;
}
// insert node at any position
void insertAtPosition(Node* &tail, Node* &head, int position, int d){
    
    // insert at start
    if(position == 1){
        insertAtHead(head,d);
        return;
    }
    
    // inserting at middle position
    Node* temp = head;
    int cnt=1;
    while(cnt<position-1){
        temp = temp->next;
        cnt++;
    }
    
    // inserting at last position
    if(temp -> next == NULL){
        insertAtTail(tail, d);
        return;
    }
    
    // creating node for d
    Node* nodeToInsert = new Node(d);
    
    nodeToInsert-> next = temp-> next;
    temp-> next = nodeToInsert;
    
}

// delete Node at any position
void deleteNode(int position, Node* &head){
    // delete first or start Node
    if(position == 1){
        Node* temp = head;
        head = head->next;
        // memory free
        temp -> next = NULL;
        delete temp;
    }
    else{
        // delete any middle node or last node
        Node* curr = head;
        Node* prev = NULL;
        
        int cnt = 1;
        while(cnt < position){
            prev = curr;
            curr=curr->next;
            cnt++;
        }
        
        // for deleting last Node
        prev-> next = curr-> next;
        curr-> next = NULL;
        delete curr;
    }
}


void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<< temp-> data<<" ";
        temp = temp-> next;
    }
    cout<<endl;
}

int main(){

    Node* node1 = new Node(10);
    
    // head points to node1
    Node* head = node1;
    Node* tail = node1;
    cout << "Initial list: ";
    print(head);
    /*
     insertAtHead(head, 12);
    cout << "After inserting 12 at head: ";
    print(head);

    insertAtHead(head, 15);
    cout << "After inserting 15 at head: ";
    print(head);
    */
    
    // tail-
    insertAtTail(tail, 12);
    cout << "After inserting 12 at tail: ";
    print(head);

    insertAtTail(tail, 15);
    cout << "After inserting 15 at tail: ";
    print(head);
    
    // at any position
    insertAtPosition(tail, head, 4, 44);
    cout << "After inserting 44 at position: ";
    print(head);
   
    //  deleting node any position 
    deleteNode(1, head);
    print(head);

    return 0;
}