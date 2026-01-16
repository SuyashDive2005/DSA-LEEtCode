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
    
    int getSize(ListNode* head) {
        int size = 0;
        while (head) {
            size++;
            head = head->next;
        }
        return size;
    }


    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int size=getSize(head);
        ListNode* cur=head;
         
         int eachbucketNodes=size/k;
         int remainNode=size%k;

         vector<ListNode*> result(k,NULL);

         cur=head;
         ListNode* prev=NULL;
         for(int i=0;i<k;i++){
            result[i]=cur;
            for(int count=1;count<=eachbucketNodes+(remainNode>0?1:0);count++){
                prev=cur;
                cur=cur->next;
            }
            if(prev)
            prev->next=NULL;
            remainNode--;
         }

         return result;

    }
};