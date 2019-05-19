/* Runtime: beats 99.69% of C++ submissions
 * Memory Usage: beats 64.81% of C++ submissions
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
typedef TreeNode* TreeNodePtr;
class Solution {
public:
    TreeNode* recoverFromPreorder(string s) {
        int curVal = 0, index = 0;
        TreeNodePtr root = nullptr;
        vector<TreeNodePtr> stack;
        int dashCount, stackLength = 0;
        while (index < s.size()) {
            dashCount = 0;
            while (s[index] == '-') {
                ++dashCount;
                ++index;
            }
            curVal = 0;
            while (index < s.size() && s[index] != '-') {
                curVal = curVal * 10 + (s[index] - '0');
                ++index;
            }
            TreeNodePtr newNode = new TreeNode(curVal);
            if (dashCount == 0) {
                root = newNode;
                stack.push_back(root);
                ++stackLength;
                continue;
            }
            while (dashCount < stackLength) {
                stack.pop_back();
                --stackLength;
            }
            if (stack[stackLength - 1]->left == nullptr) {
                stack[stackLength - 1]->left = newNode;
            } else {
                stack[stackLength - 1]->right = newNode;
            }
            stack.push_back(newNode);
            ++stackLength;
        }
        return root;
    }
};