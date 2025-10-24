/********************************************************************

    Following is the representation of the Singly Linked List Node:

    class node{
        public:
            int data;
            node * next;
            node(int data){
                this->data=data;
                this->next=NULL;
            }
    };
    
********************************************************************/

node* findMid(node* head){
    node* slow = head;    
    node* fast = head->next;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node* merge(node* left, node* right){
    node* temp = new node(0);
    node* curr = temp;

    // base case
    if(left == NULL) return right; 
    if(right == NULL) return left; 

    while(left != NULL && right != NULL){
        if(left->data < right->data) {
            curr -> next = left;
            left = left -> next;
        }
        else{
            curr -> next = right;
            right = right -> next;
        }
        curr = curr->next;
    }
        while(left != NULL){
            curr -> next = left;
            left = left -> next;
            curr = curr->next;
        }

        while(right != NULL){
            curr -> next = right;
            right = right -> next;
            curr = curr->next;
        }
    return temp->next;
}


node* mergeSort(node *head) {
    
    if(head == NULL || head->next == NULL) return head; 

    // find mid 
    node* mid = findMid(head);

    // make to parts of the LL - left and right
    node* left = head;
    node* right = mid->next;
    mid->next = NULL;
    
    // recursion fun 
    left = mergeSort(left);
    right = mergeSort(right);

    // sort LL and merge
    node* ans = merge(left, right);
    return ans;
}



















