/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


// recursion method

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        
        // base case
        if(a==NULL) return b;
        if(b==NULL) return a;

        if(a->val < b->val){
          a->next = mergeTwoLists(a->next, b);
          return a;
        }
        
        else{
            b->next = mergeTwoLists(a, b->next);
            return b;
        }

    }
};






























