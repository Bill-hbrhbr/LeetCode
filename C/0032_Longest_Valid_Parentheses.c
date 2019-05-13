struct node {
    int pos, validLen;
    struct node *next;
};

int longestValidParentheses(char* s) {
    int pos = 0, maxLen = 0, curLen = 0, prevLen = 0;
    struct node *end = malloc(sizeof(struct node)), *cur = end;
    end->pos = -1;
    end->validLen = 0;
    end->next = NULL;
    while (s[pos]) {
        if (s[pos] == '(') {
            struct node *newNode = malloc(sizeof(struct node));
            newNode->pos = pos;
            newNode->validLen = 0;
            newNode->next = cur;
            cur = newNode;
            pos++;
            continue;
        }
        if (cur->pos == -1) {
            pos++;
            cur->validLen = 0;
            continue;
        }
        curLen = pos - cur->pos + 1;
        struct node *temp = cur;
        cur = cur->next;
        free(temp);
        cur->validLen += curLen;
        maxLen = cur->validLen > maxLen ? cur->validLen : maxLen;
        pos++;
    }
    return maxLen;
}

int longestValidParentheses_dp(char* s) {
    int len = strlen(s);
    if (!len) {
        return 0;
    }
    int dp[len];
    int max = 0;
    dp[0] = 0;
    for (int i = 1; i < len; i++) {
        if (s[i] == '(') {
            dp[i] = 0;
            continue;
        }
        if (s[i - 1] == '(') {
            dp[i] = i >= 2 ? dp[i - 2] + 2 : 2;
        } else if (s[i - dp[i - 1] - 1] == '(') {
            dp[i] = dp[i - 1] + 2;
            dp[i] += i - dp[i - 1] - 2 >= 0 ? dp[i - dp[i - 1] - 2] : 0;
        } else {
            dp[i] = 0;
        }
        max = dp[i] > max ? dp[i] : max;
    }
    return max;
}