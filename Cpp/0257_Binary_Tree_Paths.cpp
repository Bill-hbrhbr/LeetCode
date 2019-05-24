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
    vector<string> binaryTreePaths(TreeNode *root) {
        vector<string> result;
        if (root == nullptr) {
            return result;
        }
        string curStr;
        dfsHelper(root, result, curStr);
        return result;
    }
private:
    void dfsHelper(TreeNode *&root, vector<string> &result, string &curStr) {
        if (root->left == nullptr && root->right == nullptr) {
            result.push_back((curStr + "->" + numToString(root->val)).substr(2));
            return;
        }
        curStr = curStr + "->" + numToString(root->val);
        if (root->left) {
            dfsHelper(root->left, result, curStr);
        }
        if (root->right) {
            dfsHelper(root->right, result, curStr);
        }
        auto iter = curStr.end();
        --iter;
        for (;;--iter) {
            if (*iter == '>') {
                break;
            }
        }
        curStr.erase(--iter, curStr.end());
    }
    string numToString(int num) {
        if (num == 0) {
            return "0";
        }
        string str;
        int n = abs(num);
        while (n > 0) {
            str += '0' + n % 10;
            n /= 10;
        }
        if (num < 0) {
            str += '-';
        }
        reverse(str.begin(), str.end());
        return str;
    }
};