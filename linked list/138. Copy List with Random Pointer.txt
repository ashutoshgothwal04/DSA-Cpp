/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

/*
Algorithm to Copy a Linked List with Random Pointer (Using Hash Map)

1. If the given head is NULL, return NULL.

2. Create an unordered_map<Node*, Node*> map
   → This will store mapping from each original node to its newly created cloned node.

3. Create the first cloned node (newHead) using the head node value.
   → newHead = new Node(head->val)
   → Store mapping: map[head] = newHead

4. Initialize:
      oldtemp = head->next      // pointer for original list traversal
      newtemp = newHead         // pointer for cloned list traversal

5. Traverse the remaining original list:
      For each node 'oldtemp':
         a. Create a new node with same value → newNode = new Node(oldtemp->val)
         b. Link it with previous clone → newtemp->next = newNode
         c. Store mapping: map[oldtemp] = newNode
         d. Move both pointers forward (oldtemp = oldtemp->next, newtemp = newtemp->next)

6. Reset both pointers to the start of their respective lists:
      oldtemp = head
      newtemp = newHead

7. Set up random pointers for the cloned list:
      While oldtemp != NULL:
         a. newtemp->random = map[oldtemp->random]
         b. Move both pointers forward

8. Return newHead as the head of the deep copied list.

Time Complexity: O(n)
Space Complexity: O(n)
*/


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        unordered_map<Node*,Node*> map;

        Node* newHead = new Node(head->val);
        Node* oldtemp = head->next;
        Node* newtemp = newHead;
        map[head] = newHead;

        while(oldtemp!=NULL){
            Node* newNode = new Node(oldtemp->val);
            newtemp->next = newNode;
            map[oldtemp] = newNode; // sync

            oldtemp = oldtemp->next;
            newtemp= newtemp->next;
        }

        // get back to starting position
        oldtemp = head;
        newtemp = newHead;

        while(oldtemp!=NULL){
           newtemp->random = map[oldtemp->random];
            oldtemp = oldtemp->next;
            newtemp= newtemp->next;
        }
        return newHead;
    }
};













