struct chosen_worker {
    int quality;
    struct chosen_worker *next;
};

struct chosen_worker * push_857(struct chosen_worker *, struct chosen_worker *);
void mergesort(double *, int*, int, int);

double mincostToHireWorkers(int* quality, int qualitySize, int* wage, int wageSize, int K) {
    int i, sum = 0;
    double ratio[qualitySize];
    int indices[qualitySize];
    for (i = 0; i < qualitySize; i++) {
        ratio[i] = wage[i]/ (double) (quality[i]);
        indices[i] = i;
    }
    mergesort(ratio, indices, 0, qualitySize - 1);
    int quality_sum = 0;
    double min_fee;
    struct chosen_worker *list = malloc(sizeof(struct chosen_worker));
    list->next = NULL;
    for (i = 0; i < K; i++) {
        struct chosen_worker *p = malloc(sizeof(struct chosen_worker));
        p->quality = quality[indices[i]];
        list = push_857(list, p);
        quality_sum += quality[indices[i]];
    }
    min_fee = quality_sum * ratio[indices[K - 1]];
    for (i = K; i < qualitySize; i++)
        if (quality[indices[i]] < list->quality) {
            quality_sum += quality[indices[i]] - list->quality;
            struct chosen_worker *p = list;
            list = list->next;
            free(p);
            p = malloc(sizeof(struct chosen_worker));
            p->quality = quality[indices[i]];
            list = push_857(list, p);
            double new_fee = ratio[indices[i]] * quality_sum;
            if (new_fee < min_fee) {
                min_fee = new_fee;
            }
        }
    return min_fee;
}


struct chosen_worker * push_857(struct chosen_worker *list, struct chosen_worker* p)
{
    struct chosen_worker *cur = list, *perv = NULL;
    while (cur->next != NULL) {
        if (p->quality < cur->quality) {
            perv = cur;
            cur = cur->next;
        }
        else 
            break;
    }
    if (perv == NULL) {
        p->next = list;
        return p;
    }
    p->next = cur;
    perv->next = p;
    return list;
}

void mergesort(double *ratio, int* a, int start, int end)
{
    if (end - start + 1 == 1)
        return;
    int split = start + (end - start + 1) / 2;
    mergesort(ratio, a, start, split - 1);
    mergesort(ratio, a, split, end);
    int *p = malloc((end - start + 1) * sizeof(int));
    //int p[end - start + 1];
    for (int i = start; i <= end; i++)
        p[i - start] = a[i];
    int i = start, j = split, k = start;
    while (i < split && j <= end) {
        if (ratio[p[i - start]] < ratio[p[j - start]])
            a[k++] = p[(i++) - start];
        else
            a[k++] = p[(j++) - start];
    }
    while (i < split)
        a[k++] = p[(i++) - start];
    while (j <= end)
        a[k++] = p[(j++) - start];
    free(p);
}