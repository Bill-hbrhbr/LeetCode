#define LIMIT (10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 + 7)

struct node {
    int index;
    int number;
    struct node *next;
};

struct node* pop(struct node *, int *, int);

int sumSubarrayMins(int* A, int ASize) {
    struct node *list = malloc(sizeof(struct node));
    list->index = 0;
    list->number = *A;
    list->next = NULL;
    int *p = A, sum = 0;
    while (++p < A + ASize) {
        int cur_num = *p, cur_index = p - A;
        while (list != NULL && cur_num < list->number) {
            list = pop(list, &sum, cur_index);
        }
        struct node *new_node = malloc(sizeof(struct node));
        new_node->index = cur_index;
        new_node->number = cur_num;
        new_node->next = list;
        list = new_node;
    }
    while (list != NULL) {
        list = pop(list, &sum, ASize);
    }
    return sum % LIMIT;
}

struct node* pop(struct node *list, int *sum, int end_index)
{
    int cur_index = list->index;
    int cur_num = list->number;
    int back = end_index - cur_index;
    int front;
    struct node *p = list;
    list = list->next;
    if (list == NULL) {
        front = cur_index + 1;
    }
    else {
        front = cur_index - list->index;
    }
    *sum += cur_num * front * back;
    *sum %= LIMIT;
    free(p);
    return list;
}