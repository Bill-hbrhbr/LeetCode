class Solution {
public:
    typedef struct ListNode* ListNodePtr;
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = l1->val + l2->val;
        l1 = l1->next;
        l2 = l2->next;
        int remain = sum / 10;
        sum %= 10;
        ListNodePtr head = new ListNode(sum), tail = head;
        while (l1 && l2) {
            sum = l1->val + l2->val + remain;
            remain = sum / 10;
            sum %= 10;
            ListNodePtr newNode = new ListNode(sum);
            tail->next = newNode;
            tail = newNode;
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNodePtr left = l1 ? l1 : l2;
        while (left) {
            sum = left->val + remain;
            remain = sum / 10;
            sum %= 10;
            ListNodePtr newNode = new ListNode(sum);
            tail->next = newNode;
            tail = newNode;
            left = left->next;
        }
        if (remain) {
            ListNodePtr newNode = new ListNode(remain);
            tail->next = newNode;
            tail = newNode;
        }
        return head;
    }
};