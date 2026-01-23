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

    // Uaing Recurssion to avoid the new space and to return modified LL.
    ListNode* removeNodes(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* nextNode=removeNodes(head->next);
        if(head->val < nextNode->val){
            return nextNode;
        }

        head->next=nextNode;
        return head;
    }
}; 