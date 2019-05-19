/* InOrder Recursive Search
 * O(n) time, O(1) space
 * Runtime: beats 98.77% of C++ submissions
 * Memory Usage: beats 80.62% of C++ submissions
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
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *first = nullptr, *second = nullptr;
        bool firstFound = false, secondFound = false, firstVal = true;
        int lastVal;
        helper(root, firstFound, secondFound, firstVal, first, second, lastVal);
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }

private:
    void helper(TreeNode* root, bool &firstFound, bool &secondFound, bool &firstVal,
               TreeNode *&first, TreeNode *&second, int &lastVal) {
        if (root == nullptr || secondFound) {
            return;
        }
        helper(root->left, firstFound, secondFound, firstVal, first, second, lastVal);
        if (firstVal) {
            firstVal = false;
        } else if (root->val < lastVal) {
            second = root;
            if (firstFound == false) {
                firstFound = true;
            } else {
                secondFound = true;
            }
        }
        lastVal = root->val;
        if (!firstFound) {
            first = root;
        }
        helper(root->right, firstFound, secondFound, firstVal, first, second, lastVal);
    }
};