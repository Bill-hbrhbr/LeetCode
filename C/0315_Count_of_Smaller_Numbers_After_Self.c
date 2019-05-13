struct treeNode {
    int val, selfCount, leftCount;
    struct treeNode *left, *right;
};

int* countSmaller(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int *counts = malloc(numsSize * sizeof(int));
    int sum;
    struct treeNode **treeHead = malloc(sizeof(struct treeNode*));
    *treeHead = NULL;
    struct treeNode *cur, *parent;
    for (int i = numsSize - 1; i >= 0; i--) {
        cur = *treeHead;
        parent = NULL;
        sum = 0;
        while (true) {
            if (cur == NULL) {
                counts[i] = sum;
                struct treeNode *newNode = malloc(sizeof(struct treeNode));
                newNode->val = nums[i];
                newNode->selfCount = 1;
                newNode->leftCount = 0;
                newNode->left = newNode->right = NULL;
                if (parent == cur) {
                    *treeHead = newNode;
                } else if (nums[i] < parent->val) {
                    parent->left = newNode;
                } else {
                    parent->right = newNode;
                }
                break;
            }
            if (cur->val == nums[i]) {
                counts[i] = sum + cur->leftCount;
                cur->selfCount++;
                break;
            }
            parent = cur;
            if (nums[i] < cur->val) {
                cur->leftCount++;
                cur = cur->left;
            } else {
                sum += cur->selfCount + cur->leftCount;
                cur = cur->right;
            }
        }
    }
    return counts;
}