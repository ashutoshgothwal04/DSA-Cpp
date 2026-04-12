int lenght(Node* head){
    int cnt = 0;
    while(head!=NULL){
        cnt++;
        head= head->next;
    }
    return cnt;
}


Node *findMiddle(Node *head) {
   int len = lenght(head);
   int mid = len/2;
   Node* temp = head;
   for(int start =0; start<mid; start++){
       temp = temp->next;
   }
   return temp;
}
