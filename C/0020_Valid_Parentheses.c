bool isValid(char* s) {
    enum bracketType {SMALL = 0, MEDIUM = 1, LARGE = 2};
    struct node {
        enum bracketType type;
        struct node *next;
    };
    int stackCount = 0, remainLen = strlen(s);
    struct node *end = malloc(sizeof(struct node)), *cur = end;
    end->type = -1;
    end->next = NULL;
    while (*s) {
        if (*s == '(' || *s == '[' || *s == '{') {
            struct node *newNode = malloc(sizeof(struct node));
            switch (*s) {
                case '(': newNode->type = SMALL; break;
                case '[': newNode->type = MEDIUM; break;
                case '{': newNode->type = LARGE; break;
            }
            newNode->next = cur;
            cur = newNode;
            stackCount++;
            s++;
            remainLen--;
            if (stackCount > remainLen) {
                return false;
            }
            continue;
        }
        if (cur->next == NULL) {
            return false;
        }
        if (*s == ')' && cur->type != SMALL) {
            return false;
        }
        if (*s == ']' && cur->type != MEDIUM) {
            return false;
        }
        if (*s == '}' && cur->type != LARGE) {
            return false;
        }
        struct node *temp = cur;
        cur = cur->next;
        free(temp);
        s++;
        stackCount--;
        remainLen--;
    }
    return true;
}