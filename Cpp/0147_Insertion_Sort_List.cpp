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
    ListNode* insertionSortList(ListNode* head) {
        vector<int> vec;
        auto iter = back_inserter(vec);
        while (head != nullptr) {
            *iter = head->val;
            head = head->next;
        }
        sort(vec.begin(), vec.end(), [] (int x, int y)->bool { return x > y; });
        ListNode *result = nullptr;
        for (auto it = vec.cbegin(); it != vec.cend(); ++it) {
            ListNode *newNode = new ListNode(*it);
            newNode->next = result;
            result = newNode;
        }
        return result;
    }
};