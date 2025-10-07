/*************************************************
    
class Node {
public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

*************************************************/

Node* floydDetectLoop(Node* head) { // detect loop
    if (head == NULL) return NULL;

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        fast = fast->next;
            if(fast != NULL){
                fast= fast->next;
            }

        slow= slow->next;

        if(slow == fast) return slow;
    }
    return NULL;
}

Node* getStartingNode(Node* head) {
    if (head == NULL) return NULL;

    Node* intersect = floydDetectLoop(head);
    if (intersect == NULL) return NULL; 

    Node* slow = head;
    while(slow != intersect){
        intersect = intersect-> next;
        slow = slow -> next;
    }
    return slow;
}

Node* removeLoop(Node* head) {
    if (head == NULL) return NULL;

    Node* startPoint = getStartingNode(head);
    Node* temp = startPoint; 

    if(startPoint == NULL) return head;

    while(temp-> next != startPoint){
        temp = temp->  next;
    }
    temp->next = NULL;
    return head;
}




















