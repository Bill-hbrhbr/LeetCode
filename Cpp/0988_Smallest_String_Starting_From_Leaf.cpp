/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <algorithm>
class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        string minStr;
        string curStr;
        if (root == nullptr) {
            return minStr;
        }
        dfsHelper(root, minStr, curStr);
        return minStr;
    }
private:
    void dfsHelper(TreeNode *&root, string &minStr, string &curStr) {
        if (root->left == nullptr && root->right == nullptr) {
            string newStr = curStr + static_cast<char> ('a' + root->val);
            reverse(newStr.begin(), newStr.end());
            if (minStr.size() == 0) {
                minStr = newStr;
            } else if (minStr.compare(newStr) > 0) {
                minStr = newStr;
            }
            return;
        }
        curStr += 'a' + root->val;
        if (root->left) {
            dfsHelper(root->left, minStr, curStr);
        }
        if (root->right) {
            dfsHelper(root->right, minStr, curStr);
        }
        curStr.erase(curStr.end() - 1, curStr.end());
    }
};