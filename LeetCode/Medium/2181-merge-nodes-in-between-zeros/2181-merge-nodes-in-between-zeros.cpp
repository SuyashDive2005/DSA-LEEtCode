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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* p1=head->next;
        ListNode* p2=p1;

        while(p2){
            int addition=0;
            while(p2 && p2->val!=0){
                addition+=p2->val;
                p2=p2->next;
            }
            p1->val=addition;
            p2=p2->next;
            p1->next=p2;
            p1=p1->next;
            addition=0;
        }
        return head->next;
    }
};