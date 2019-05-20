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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        int curDepth = 0, vecDepth = -1;
        helper(root, result, curDepth, vecDepth);
        return result;
    }
    
private:
    void helper(TreeNode* root, vector<int> &result, int &curDepth, int &vecDepth) {
        if (root == nullptr) {
            return;
        }
        if (curDepth > vecDepth) {
            result.push_back(root->val);
            ++vecDepth;
        }
        ++curDepth;
        helper(root->right, result, curDepth, vecDepth);
        helper(root->left, result, curDepth, vecDepth);
        --curDepth;
    }
};