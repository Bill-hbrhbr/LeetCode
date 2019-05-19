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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }
        ListNode *fast = head, *slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *list1 = head, *list2 = slow;
        if (fast != nullptr) {
            list2 = list2->next;
        }
        ListNode *prev = nullptr, *curr = list2, *next;
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        list2 = prev;
        while (list2 != nullptr) {
            if (list1->val != list2->val) {
                return false;
            }
            list1 = list1->next;
            list2 = list2->next;
        }
        return true;
    }
};