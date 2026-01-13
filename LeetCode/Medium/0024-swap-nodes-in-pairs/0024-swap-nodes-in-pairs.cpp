class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        
        ListNode* cur = head;
        ListNode* prev = nullptr;
        ListNode* newHead = head->next;
        
        while (cur != nullptr && cur->next != nullptr) {
            ListNode* nxt = cur->next;
            ListNode* nxtPair = nxt->next;

            nxt->next = cur;
            cur->next = nxtPair;

            if (prev != nullptr) prev->next = nxt;

            prev = cur;
            cur = nxtPair;
        }
        
        return newHead;
    }
};
