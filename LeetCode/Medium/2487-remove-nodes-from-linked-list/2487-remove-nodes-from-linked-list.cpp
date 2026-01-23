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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*>st;
        ListNode* cur=head;
        while(cur){
            st.push(cur);
            cur=cur->next;  
        }

        cur=st.top();
        st.pop();

        int maxNode=cur->val;

        ListNode* resultHead=new ListNode(cur->val);
        while(!st.empty()){
            cur=st.top();
            st.pop();
            if(cur->val < maxNode){
                continue;
            }else{
                ListNode* newNode = new ListNode(cur->val);
                newNode->next=resultHead;
                resultHead=newNode;
                maxNode=cur->val;
            }
        }
        
        return resultHead;

    }
}; 