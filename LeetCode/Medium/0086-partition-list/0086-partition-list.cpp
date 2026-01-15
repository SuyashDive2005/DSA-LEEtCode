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
    ListNode* partition(ListNode* head, int x) {
        ListNode* small=new ListNode(0);
        ListNode* large=new ListNode(0);
        ListNode* s_ptr=small;
        ListNode* l_ptr=large;

        while(head!=nullptr){
            if(head->val<x){
                s_ptr->next=new ListNode(head->val);
                s_ptr=s_ptr->next;
            }
            else{
                l_ptr->next=new ListNode(head->val);
                l_ptr=l_ptr->next;
            }
            head=head->next;
        }
        s_ptr->next=large->next;

        return small->next;
    }
};