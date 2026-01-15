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
    ListNode *reverse(ListNode* head ){
        if(!head || !head->next){
            return head;
        }

        ListNode *newNode = reverse(head->next);
        ListNode *front = head->next;
        front->next = head;
        head->next = NULL;
        return newNode;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverse(l1);
        l2=reverse(l2);
        int sum=0;
        int carry = 0;
        ListNode *ans=new ListNode();
        while(l1 || l2){
            if(l1){
                sum+=l1->val;
                l1=l1->next;
            }

            if(l2){
                sum+=l2->val;
                l2=l2->next;
            }

            ans->val=sum%10;
            carry=sum/10;
            ListNode *newNode = new ListNode(carry);
            newNode->next=ans;
            ans=newNode;
            sum=carry;
            
        }
        if(carry ==0){
                return ans->next;
            }
        return ans;
    }
};