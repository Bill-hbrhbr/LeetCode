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
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr) {
            return false;
        }
        int curSum = 0;
        bool found = false;
        dfsHelper(root, sum, curSum, found);
        return found;
    }
private:
    void dfsHelper(TreeNode *&root, int &sum, int &curSum, bool &found) {
        if (found) {
            return;
        }
        if (root->left == nullptr && root->right == nullptr) {
            if (sum == curSum + root->val) {
                found = true;
            }
            return;
        }
        curSum += root->val;
        if (root->left) {
            dfsHelper(root->left, sum, curSum, found);
        }
        if (root->right) {
            dfsHelper(root->right, sum, curSum, found);
        }
        curSum -= root->val;
    }
};