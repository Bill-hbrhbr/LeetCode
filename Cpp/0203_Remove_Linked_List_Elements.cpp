/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    typedef struct ListNode* ListNodePtr;
    ListNode* removeElements(ListNode* head, int val) {
        ListNodePtr top = new ListNode(0);
        top->next = head;
        ListNodePtr prev = top, curr = head;
        while (curr != nullptr) {
            if (curr->val == val) {
                ListNodePtr temp = curr;
                curr = curr->next;
                prev->next = curr;
                delete temp;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        head = top->next;
        delete top;
        return head;
    }
};