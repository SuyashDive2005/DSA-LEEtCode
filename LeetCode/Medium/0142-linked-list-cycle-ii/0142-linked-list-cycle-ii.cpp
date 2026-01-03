/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *dum=head;
        ListNode *fast=dum,*slow=dum;

        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                 slow=dum;
                 while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                 }
                 return slow;

            }
            
        }
       
        return nullptr;
        
    }
};