/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
typedef Node* NodePtr;
class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            return root;
        }
        vector<NodePtr> vec{root, nullptr};
        while (vec.size() > 1) {
            vector<NodePtr> newVec;
            for (int i = 0; i < vec.size() - 1; ++i) {
                vec[i]->next = vec[i + 1];
                if (vec[i]->left) {
                    newVec.push_back(vec[i]->left);
                }
                if (vec[i]->right) {
                    newVec.push_back(vec[i]->right);
                }
            }
            vec = newVec;
            vec.push_back(nullptr);
        }
        return root;
    }
};