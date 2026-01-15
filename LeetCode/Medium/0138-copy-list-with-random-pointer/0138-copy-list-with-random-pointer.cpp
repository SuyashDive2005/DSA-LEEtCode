/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr){
            return head;
        }

        unordered_map<Node*,Node*> mp;
        Node* cur=head;
        Node* prev=NULL;
        Node* nHead=NULL;
        while(cur){
            Node* temp=new Node(cur->val);
            mp[cur]=temp;
            if(nHead==NULL){
                nHead=temp;
                prev=nHead;
            }
            else{
                prev->next=temp;
                prev=temp;
            }
            cur=cur->next;
        }

        cur=head;
        Node * newcur=nHead;
        while(cur){
            if(cur->random==nullptr){
                newcur->random=NULL;
            }
            else{

                
                newcur->random=mp[cur->random];
            }

            cur=cur->next;
            newcur=newcur->next;

        }
        return nHead;
    }
};