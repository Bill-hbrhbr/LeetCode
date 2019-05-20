/* O(nlog(n))
 * Uses quicksort to sort the mapping
 * Runtime: 0ms beats 100% of C++ submissions
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
struct NodeInfo {
    int val;
    int x;
    int y;
    NodeInfo(int _val, int _x, int _y) : val(_val), x(_x), y(_y) {}
};

typedef TreeNode* TreeNodePtr;
typedef NodeInfo* NodeInfoPtr;
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int rootX = 0, rootY = 0;
        vector<NodeInfoPtr> record;
        traverse(root, rootX, rootY, record);
        quicksort(record, 0, record.size() - 1);
        vector<vector<int>> result(1);
        int index = 0;
        rootX = record[0]->x;
        for (int i = 0; i < record.size(); ++i) {
            if (record[i]->x == rootX) {
                result[index].push_back(record[i]->val);
            } else {
                rootX = record[i]->x;
                result.push_back({});
                result[++index].push_back(record[i]->val);
            }
        }
        for (auto iter = record.cbegin(); iter != record.cend(); ++iter) {
            delete *iter;
        }
        return result;
    }
private:
    int compare(const NodeInfoPtr &p, const NodeInfoPtr &q) {
        if (p->x != q->x) {
            return p->x - q->x;
        } else if (p->y != q->y) {
            return q->y - p->y;
        } else {
            return p->val - q->val;
        }
    }
    void swap(vector<NodeInfoPtr> &record, int i, int j) {
        NodeInfoPtr temp = record[i];
        record[i] = record[j];
        record[j] = temp;
    }
    int partition(vector<NodeInfoPtr> &record, int low, int high) {
        int pivot = low, left = low + 1, right = high;
        while (true) {
            while (left <= right && compare(record[pivot], record[left]) >= 0) {
                ++left;
            }
            while (left <= right && compare(record[pivot], record[right]) <= 0) {
                --right;
            }
            if (left < right) {
                swap(record, left, right);
            } else {
                swap(record, pivot, right);
                return right;
            }
        }
    }
    void quicksort(vector<NodeInfoPtr> &record, int low, int high) {
        if (low >= high) {
            return;
        }
        int pIndex = partition(record, low, high);
        quicksort(record, low, pIndex - 1);
        quicksort(record, pIndex + 1, high);
    }
    void traverse(TreeNodePtr root, int &x, int &y, vector<NodeInfoPtr> &record) {
        if (root == nullptr) {
            return;
        }
        record.push_back(new NodeInfo(root->val, x, y));
        --y;
        --x;
        traverse(root->left, x, y, record);
        x += 2;
        traverse(root->right, x, y, record);
        --x;
        ++y;
    }
};