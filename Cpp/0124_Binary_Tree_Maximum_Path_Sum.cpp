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
    int maxPathSum(TreeNode* root) {
        int *maxSum = nullptr;
        helper(root, maxSum);
        int result = *maxSum;
        delete maxSum;
        return result;
    }
private:
    int helper(TreeNode* root, int *&maxSum) {
        if (root == nullptr) {
            return 0;
        }
        int left = helper(root->left, maxSum);
        int right = helper(root->right, maxSum);
        int newVal = left + right + root->val;
        if (left < 0) {
            newVal -= left;
        }
        if (right < 0) {
            newVal -= right;
        }
        if (maxSum == nullptr) {
            maxSum = new int(newVal);
        } else {
            *maxSum = newVal > *maxSum ? newVal : *maxSum;
        }
        if (left <= 0 && right <= 0) {
            return root->val;
        }
        return left > right ? left + root->val : right + root->val;
    }
};