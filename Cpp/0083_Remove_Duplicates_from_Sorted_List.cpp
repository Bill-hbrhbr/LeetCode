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
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNodePtr prev = head, curr = head->next;
        while (curr) {
            if (curr->val == prev->val) {
                ListNodePtr temp = curr;
                curr = curr->next;
                prev->next = curr;
                delete temp;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};