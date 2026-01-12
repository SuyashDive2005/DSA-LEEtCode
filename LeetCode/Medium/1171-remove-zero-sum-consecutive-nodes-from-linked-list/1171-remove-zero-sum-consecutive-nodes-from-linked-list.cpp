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
    ListNode* removeZeroSumSublists(ListNode* head) {
        int prefsum=0;
        unordered_map<int,ListNode*> mp;

        ListNode* dummyNode=new ListNode(0);
        dummyNode->next=head;
        mp[0]=dummyNode;
        while(head!=NULL){
            prefsum+=head->val;
            if(mp.find(prefsum)!=mp.end()){
                ListNode* start=mp[prefsum];
                ListNode* temp=start;

                int psum=prefsum;
                while(temp!=head){
                    temp=temp->next;
                    psum+=temp->val;
                    if(temp!=head){
                        mp.erase(psum);
                    }
                }

                start->next=head->next;
            }
            else{
                mp[prefsum]=head;
            }
            head=head->next;
        }

        return dummyNode->next;

    }
};