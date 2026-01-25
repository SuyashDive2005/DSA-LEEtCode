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
    ListNode* sortList(ListNode* head) {
        vector<int>vec;
        if(!head){
            return head;
        }

        ListNode* cur=head;
        while(cur){
            vec.push_back(cur->val);
            cur = cur->next;
        }
        sort(vec.begin(),vec.end());
        
        cur=head;
        for(int i=0;i<vec.size();i++){
            head->val=vec[i];
            head=head->next;
        }

        return cur;


    }
};