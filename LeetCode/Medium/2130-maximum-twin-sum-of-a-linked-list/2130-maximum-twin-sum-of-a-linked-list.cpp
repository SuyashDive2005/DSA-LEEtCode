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
class Solution {
public:
    int pairSum(ListNode* head) {

        if(head==nullptr) return 0;
        ListNode *slow=head;
        ListNode *fast=head;
        

        while(fast!=nullptr && fast->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
        }

        ListNode *mid=slow;
        int ans=INT_MIN;
        // reversing ll
        ListNode*prev=NULL;
        ListNode *nextNode=NULL;
        while(mid!=nullptr){
            nextNode=mid->next;
            mid->next=prev;
            prev=mid;
            mid=nextNode;

        }


        ListNode *curr=head;
        while(prev!=nullptr){
            ans=max(ans,curr->val+prev->val);
            prev=prev->next;
            curr=curr->next;

        }
        return ans;
    }
};