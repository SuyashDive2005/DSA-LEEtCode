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
    ListNode* mergetwo(ListNode* l1,ListNode* l2){
        if(l1==nullptr) return l2;
        if(l2==nullptr) return l1;
        
        if(l1->val<=l2->val){
            l1->next=mergetwo(l1->next,l2);
            return l1;
        } else{
            l2->next=mergetwo(l1,l2->next);
            return l2;
        }
        return NULL;
    }

    ListNode* partAndmerge(int start,int end,vector<ListNode*>& lists){
        if(start>end){
            return NULL;
        }
        if(start==end){
            return lists[start];
        }
       
       int mid=(start+end)/2;
       ListNode* L1=partAndmerge(start,mid,lists);
       ListNode* L2=partAndmerge(mid+1,end,lists);
       return mergetwo(L1,L2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k=lists.size();
        if(k==0){
            return NULL;
        }

        return partAndmerge(0,k-1,lists);
    }
};