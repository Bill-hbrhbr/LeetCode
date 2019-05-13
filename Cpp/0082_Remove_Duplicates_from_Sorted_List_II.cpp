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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNodePtr top = new ListNode(0);
        top->next = head;
        bool duplicate = false;
        ListNodePtr link = top, prev = head, curr = head->next;
        while (curr) {
            if (curr->val == prev->val) {
                duplicate = true;
                ListNodePtr temp = curr;
                curr = curr->next;
                prev->next = curr;
                delete temp;
            } else if (duplicate) {
                duplicate = false;
                link->next = curr;
                delete prev;
                prev = curr;
                curr = curr->next;
            } else {
                link = prev;
                prev = curr;
                curr = curr->next;
            }
        }
        if (duplicate) {
            delete prev;
            link->next = nullptr;
        }
        head = top->next;
        delete top;
        return head;
    }
};