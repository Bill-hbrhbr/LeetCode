//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};
 
void finish(struct ListNode *, struct ListNode *, int); 

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* list = malloc(sizeof(struct ListNode));
    list->next = NULL;
    struct ListNode* prev = list;
    int extra = 0;
    while (l1 != NULL && l2 != NULL) {
        struct ListNode* new_node = malloc(sizeof(struct ListNode));
        new_node->next = NULL;
        new_node->val = l1->val + l2->val + extra;
        extra = new_node->val / 10;
        new_node->val %= 10;
        prev->next = new_node;
        prev = new_node;
        l1 = l1->next;
        l2 = l2->next;
    }
    if (l1 == NULL && l2 == NULL) {
        if (extra) {
            struct ListNode* new_node = malloc(sizeof(struct ListNode));
            new_node->val = extra;
            new_node->next = NULL;
            prev->next = new_node;
        }
    }
    else if (l1 == NULL)
        finish(prev, l2, extra);
    else
        finish(prev, l1, extra);
    
    return list->next;
}

void finish(struct ListNode *prev, struct ListNode *list, int extra)
{
    prev->next = list;
    while (list != NULL) {
        list->val += extra;
        if (list->val > 9) {
            extra = 1;
            list->val -= 10;
        }
        else {
            extra = 0;
            break;
        }
        prev = list;
        list = list->next;
    }
    if (extra) {
        struct ListNode *new_node = malloc(sizeof(struct ListNode));
        new_node->val = extra;
        new_node->next = NULL;
        prev->next = new_node;
    }
}