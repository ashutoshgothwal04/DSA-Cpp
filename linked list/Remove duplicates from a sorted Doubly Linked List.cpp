/**
 * Definition of doubly linked list:
 * class Node {
 * public:
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next, Node *prev) {
 *          this->data = data;
 *          this->prev = prev;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node * removeDuplicates(Node *head){
    // empty list 
    if(head == NULL) return NULL;

    Node* curr = head;

   while(curr != NULL){
       if((curr -> next != NULL) && curr->data == curr->next->data){
           Node* nextKaNext = curr->next->next;
           Node* deleteNode = curr->next;
           delete(deleteNode); // memory free
           curr->next = nextKaNext;
       }
       else{
           curr = curr -> next;
       }
   }
    return head;
}























