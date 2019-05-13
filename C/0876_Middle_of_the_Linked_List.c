//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* middleNode(struct ListNode* head) {
    int count = 0;
    struct ListNode *cur = head;
    while (cur != NULL) {
        count++;
        cur = cur->next;
    }
    count = count / 2 + 1;
    cur = head;
    while (count > 1) {
        cur = cur->next;
        count--;
    }
    return cur;
}