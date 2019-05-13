//Using Linked List to implement radix sort
//10 digit buckets + 1 sorted buckets
//Time complexity: O(kN)
//Space complexity: O(N)
//k being the highest count of digits in a number

struct node {
    int num, remain;
    struct node *next;
};

int firstMissingPositive(int* nums, int numsSize) {
    int minPos = 0, maxPos = 0, maxDigits = 0;
    struct node *list = malloc(sizeof(struct node)), *cur = list, *prev = NULL;
    list->next = NULL;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0) {
            if (minPos == 0) {
                minPos = nums[i];
            } else if (nums[i] < minPos) {
                minPos = nums[i];
            }
            if (maxPos < nums[i]) {
                maxPos = nums[i];
            }
            struct node *newNode = malloc(sizeof(struct node));
            newNode->num = newNode->remain = nums[i];
            newNode->next = NULL;
            cur->next = newNode;
            cur = newNode;
        }
    }
    if (minPos > 1 || maxPos < 1) {
        return 1;
    }
    while (maxPos > 0) {
        maxPos /= 10;
        maxDigits++;
    }
    
    //Create and initialize 10 buckets for sorting
    struct node *temp[10];
    for (int i = 0; i < 10; i++) {
        temp[i] = malloc(sizeof(struct node));
    }
    struct node *tempCur[10];
    for (int i = 0; i < maxDigits; i++) {
        for (int j = 0; j < 10; j++) {
            tempCur[j] = temp[j];
            tempCur[j]->next = NULL;
        }
        prev = list;
        cur = list->next;
        
        //Split the list
        while (cur != NULL) {
            if (cur->remain == 0) {
                prev = cur;
                cur = cur->next;
                continue;
            }
            int digit = cur->remain % 10;
            cur->remain /= 10;
            tempCur[digit]->next = cur;
            cur = cur->next;
            prev->next = cur;
            tempCur[digit] = tempCur[digit]->next;
            tempCur[digit]->next = NULL;
        }
        
        //Merge the lists, special treatment if no items in buckets
        for (int j = 0; j < 10; j++) {
            prev->next = temp[j]->next;
            if (tempCur[j] != temp[j])
                prev = tempCur[j];
        }
    }
    
    //Find the least missing positive number using the sorted list
    cur = list->next;
    int curNum = 1;
    while (cur != NULL) {
        if (cur->num == curNum + 1) {
            curNum++;
        } else if (cur->num != curNum) {
            return curNum + 1;
        }
        cur = cur->next;
    }
    return curNum + 1;
}