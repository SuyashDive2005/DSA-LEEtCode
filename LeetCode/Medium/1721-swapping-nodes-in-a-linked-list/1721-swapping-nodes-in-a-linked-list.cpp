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
    ListNode* swapNodes(ListNode* head, int k) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        int l=0;
        ListNode *dum=head;
        while(dum!=NULL){
            
            dum=dum->next;
            l++;
        }

        ListNode* node1=head;
        int k_2=l-k+1;
        while( k>1){
            node1=node1->next;
            k--;
        }
        ListNode* node2=head;
        while(k_2>1){
            node2=node2->next;
            k_2--;
        }
        swap(node1->val,node2->val);

        return head;


    }
};