/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flattenDFS(Node* head) {
        Node* curr = head;
        Node* last = nullptr;

        while (curr) {
            Node* nextNode = curr->next;

            if (curr->child) {
                Node* childHead = curr->child;
                Node* childTail = flattenDFS(childHead);

                curr->next = childHead;
                childHead->prev = curr;
                curr->child = NULL;

                if (nextNode) {
                    childTail->next = nextNode;
                    nextNode->prev = childTail;
                }

                last = childTail;
                curr = childTail;
            } else {
                last = curr;
            }

            curr = curr->next;
        }

        return last;
    }

    Node* flatten(Node* head) {
        if (!head) return NULL;
        flattenDFS(head);
        return head;
    }
};