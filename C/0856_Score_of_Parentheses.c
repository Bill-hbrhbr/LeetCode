struct node {
    int pos;
    struct node *next;
};

int pop(struct node*);

int scoreOfParentheses(char* S) {
    int len = strlen(S);
    int dp[len];
    struct node *stack = malloc(sizeof(struct node));
    stack->next = NULL;
    for (int i = 0; i < len; i++) {
        if (S[i] == '(') {
            dp[i] = -1;
            struct node *newNode = malloc(sizeof(struct node));
            newNode->pos = i;
            newNode->next = stack->next;
            stack->next = newNode;
            continue;
        }
        int pos = pop(stack);
        if (S[i - 1] == '(') {
            dp[i] = 1;
        } else {
            dp[i] = dp[i - 1] * 2;
        }
        if (pos > 0 && S[pos - 1] == ')') {
            dp[i] += dp[pos - 1];
        }
    }
    return dp[len - 1];
}

int pop(struct node* stack) {
    struct node *temp = stack->next;
    stack->next = temp->next;
    int pos = temp->pos;
    free(temp);
    return pos;
}