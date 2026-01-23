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
    ListNode* reverse(ListNode* head) {
        if (!head) {
            return head;
        }

        ListNode* prev = NULL;
        ListNode* cur = head;

        while (cur) {
            ListNode* nextNode = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextNode;
        }
        return prev;
    }
    ListNode* doubleIt(ListNode* head) {

        head = reverse(head);
        ListNode* cur = head;
        ListNode* prev = NULL;

        int cary = 0;

        while (cur) {
            int newVal = (cur->val) * 2 + cary;
            cur->val = newVal % 10;
            cary = (newVal >= 10) ? 1 : 0;
            prev = cur;
            cur = cur->next;
        }
        if (cary != 0) {
            ListNode* newHead = new ListNode(cary);
            prev->next = newHead;
        }
        return reverse(head);
    }
};