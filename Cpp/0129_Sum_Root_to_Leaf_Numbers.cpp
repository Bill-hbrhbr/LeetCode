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
    static int sum;
    static int curVal;
    int sumNumbers(TreeNode *root) {
        sum = 0;
        curVal = 0;
        if (root == nullptr) {
            return 0;
        }
        dfsHelper(root);
        return sum;
    }
private:
    void dfsHelper(TreeNode *&root) {
        if (root->left == nullptr && root->right == nullptr) {
            sum += curVal * 10 + root->val;
            return;
        }
        curVal = curVal * 10 + root->val;
        if (root->left) {
            dfsHelper(root->left);
        }
        if (root->right) {
            dfsHelper(root->right);
        }
        curVal /= 10;
    }
};
int Solution::sum = 0;
int Solution::curVal = 0;