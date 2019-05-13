//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct node {
    int val;
    struct node* next;
};

void recursiveLeft(struct TreeNode* root, struct node *list);
void recursiveRight(struct TreeNode* root, struct node *list, bool *isMatch);

bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2) {
    struct node *list = malloc(sizeof(struct node));
    list->next = NULL;
    recursiveLeft(root1, list);
    bool *isMatch = malloc(sizeof(bool));
    bool match = true;
    isMatch = &match;
    recursiveRight(root2, list, isMatch);
    return match;
}

void recursiveLeft(struct TreeNode* root, struct node *list) {
    if (root == NULL) {
        return;
    }
    if (root->left == NULL && root->right == NULL) {
        struct node *newNode = malloc(sizeof(struct node));
        newNode->val = root->val;
        newNode->next = list->next;
        list->next = newNode;
        return;
    }
    recursiveLeft(root->left, list);
    recursiveLeft(root->right, list);
}

void recursiveRight(struct TreeNode* root, struct node *list, bool *isMatch) {
    if (root == NULL) {
        return;
    }
    if (*isMatch && root->left == NULL && root->right == NULL) {
        if (list->next->val != root->val) {
            *isMatch = false;
            return;
        }
        struct node *temp = list->next;
        list->next = temp->next;
        free(temp);
        return;
    }
    if (*isMatch) {
        recursiveRight(root->right, list, isMatch);
        recursiveRight(root->left, list, isMatch);
    } else {
        return;
    }
}