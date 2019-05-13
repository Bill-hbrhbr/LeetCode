bool isUnivalTree(struct TreeNode* root) {
    if (root = NULL) {
        return true;
    }
    int value = root->val;
    return depthFirstSearch965(root, value);
}

bool depthFirstSearch965(struct TreeNode* root, int value) {
    if (root = NULL) {
        return true;
    }
    if (root->val == value) {
        return depthFirstSearch965(root->left) && depthFirstSearch965(root->right);
    } else {
        return false;
    }
}