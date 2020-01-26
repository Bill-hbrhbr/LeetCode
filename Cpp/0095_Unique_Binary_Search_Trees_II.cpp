/* Dynamic Programming Solution:
 * Runtime: 20ms beats 89.70% of C++ submissions
 * Memory Usage: 13.8MB beats 86.96% of C++ submissions
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
    vector<TreeNodePtr> generateTrees(int n) {
        if (n == 0) {
            return {};
        }
        vector<vector<TreeNodePtr>> dp_subtrees;
        dp_subtrees.push_back({nullptr});
        int nodeCount, rootVal, leftCount, rightCount;
        for (nodeCount = 1; nodeCount <= n; ++nodeCount) {
            dp_subtrees.push_back({});
            for (rootVal = 1; rootVal <= nodeCount; ++rootVal) {
                leftCount = rootVal - 1;
                rightCount = nodeCount - rootVal;
                for (int i = 0; i < dp_subtrees[leftCount].size(); ++i) {
                    for (int j = 0; j < dp_subtrees[rightCount].size(); ++j) {
                        TreeNodePtr newNode = new TreeNode(rootVal);
                        int valueShift = 0;
                        newNode->left = copySubtree(dp_subtrees, leftCount, i, valueShift);
                        valueShift = rootVal;
                        newNode->right = copySubtree(dp_subtrees, rightCount, j, valueShift);
                        dp_subtrees[nodeCount].push_back(newNode);
                    }
                }
            }
        }
        return dp_subtrees[n];
        
    }
private:
    TreeNodePtr copySubtree(vector<vector<TreeNodePtr>> &dp_subtrees,
                            int &subtreeNodeCount, int &index, int &valueShift) {
        TreeNodePtr newRoot;
        helper(newRoot, dp_subtrees[subtreeNodeCount][index], valueShift);
        return newRoot;
    }
    void helper(TreeNodePtr &newRoot, TreeNodePtr &curr, int &valueShift) {
        if (curr == nullptr) {
            newRoot = nullptr;
            return;
        }
        newRoot = new TreeNode(curr->val + valueShift);
        helper(newRoot->left, curr->left, valueShift);
        helper(newRoot->right, curr->right, valueShift);
    }
};