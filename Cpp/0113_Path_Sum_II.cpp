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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> curVec;
        if (root == nullptr) {
            return result;
        }
        int curSum = 0;
        dfsHelper(root, result, curVec, sum, curSum);
        return result;
    }
private:
    void dfsHelper(TreeNode *&root, vector<vector<int>> &result, 
                   vector<int> &curVec, int &sum, int &curSum) {
        if (root->left == nullptr && root->right == nullptr) {
            if (sum == curSum + root->val) {
                result.push_back(curVec);
                result[result.size() - 1].push_back(root->val);
            }
            return;
        }
        curSum += root->val;
        curVec.push_back(root->val);
        if (root->left) {
            dfsHelper(root->left, result, curVec, sum, curSum);
        }
        if (root->right) {
            dfsHelper(root->right, result, curVec, sum, curSum);
        }
        curSum -= root->val;
        curVec.pop_back();
    }
};