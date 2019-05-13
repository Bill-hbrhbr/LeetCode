struct headTreeNode {
    int base;
    struct listNode **listHead;
    struct headTreeNode *left;
    struct headTreeNode *right;
};

struct listNode {
    int logV;
    int count;
    struct listNode *next;
};

struct treeNodeStack {
    struct headTreeNode *addr;
    struct treeNodeStack **next;
};

bool canReorderDoubled(int* A, int ASize) {
    if (ASize == 0) {
        return true;
    }
    struct headTreeNode **treeHead = malloc(sizeof(*treeHead));
    struct headTreeNode *cur, *prev;
    *treeHead = NULL;
    int value, logV, stackCount, zeroCount = 0;
    
    struct listNode *listCur, *listPrev;
    
    for (int i = 0; i < ASize; i++) {
        value = A[i];
        if (value == 0) {
            zeroCount++;
            continue;
        }
        logV = 0;
        while (value % 2 == 0) {
            value /= 2;
            logV++;
        }
        prev = NULL;
        cur = *treeHead;
        while (cur != NULL) {
            prev = cur;
            if (value == cur->base) {
                break;
            }
            if (value < cur->base) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }
        if (cur == NULL) {
            struct headTreeNode *newTreeNode = malloc(sizeof(*newTreeNode));
            newTreeNode->base = value;
            newTreeNode->listHead = malloc(sizeof(listCur));
            listCur = *(newTreeNode->listHead) = malloc(sizeof(struct listNode));
            listCur->logV = logV;
            listCur->count = 1;
            listCur->next = NULL;
            newTreeNode->left = newTreeNode->right = NULL;
            if (prev == NULL) {
                *treeHead = newTreeNode;
            } else if (prev->base > value) {
                prev->left = newTreeNode;
            } else {
                prev->right = newTreeNode;
            }
            cur = newTreeNode;
        } else {
            listCur = *(cur->listHead);
            listPrev = NULL;
            while (listCur != NULL && logV > listCur->logV) {
                listPrev = listCur;
                listCur = listCur->next;
            }
            if (listCur != NULL && logV == listCur->logV) {
                listCur->count++;
                continue;
            }
            struct listNode *newListNode = malloc(sizeof(struct listNode));
            newListNode->logV = logV;
            newListNode->count = 1;
            newListNode->next = listCur;
            if (listPrev == NULL) {
                *(cur->listHead) = newListNode;
            } else {
                listPrev->next = newListNode;
            }
        }
    }
    if (zeroCount % 2) {
        return false;
    }
    
    stackCount = 1;
    cur = *treeHead;
    if (cur == NULL) {
        return true;
    }
    prev = NULL;
    struct treeNodeStack *stackHead = malloc(sizeof(struct treeNodeStack));
    stackHead->addr = cur;
    stackHead->next = NULL;
    struct treeNodeStack *temp;
    
    while (stackCount-- > 0) {
        temp = stackHead;
        stackHead = stackHead->next;
        
        listPrev = *(temp->addr->listHead);
        listCur = listPrev->next;
        while (listCur != NULL) {
            if (listPrev->count != 0) {
                if (listCur->logV - listPrev->logV > 1) {
                    return false;
                }
                listCur->count -= listPrev->count;
                listPrev->count = 0;
                if (listCur->count < 0) {
                    return false;
                }
            }
            listPrev = listCur;
            listCur = listCur->next;
        }
        if (listPrev->count != 0) {
            return false;
        }
        stackPush954(&stackHead, temp->addr->right, &stackCount);
        stackPush954(&stackHead, temp->addr->left, &stackCount);
        free(temp);
    }
    return true;
}

void stackPush954(struct treeNodeStack **head, struct headTreeNode* node, int* stackCount) {
    if (node == NULL) {
        return;
    }
    (*stackCount)++;
    struct treeNodeStack *newNode = malloc(sizeof(*newNode));
    newNode->addr = node;
    newNode->next = *head;
    *head = newNode;
    return;
}