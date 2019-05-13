#define PRIME 31
#define M 100

void updateHash884(char (*hash)[210], char* s, bool* added);

char** uncommonFromSentences(char* A, char* B, int* returnSize) {
    char hash[M][210] = {0};
    bool added[M] = {0};
    char **list = malloc(0);
    int total = 0;
    updateHash884(hash, A, added);
    updateHash884(hash, B, added);
    for (int i = 0; i < M; i++) {
        if (added[i]) {
            list = realloc(list, sizeof(*list) * (total + 1));
            list[total] = malloc(210);
            strcpy(list[total++], hash[i]);
        }
    }
    *returnSize = total;
    return list;
}

void updateHash884(char (*hash)[210], char* s, bool* added) {
    char str[210] = {0};
    int hashValue, count;
    while (1) {
        count = 0;
        hashValue = 0;
        while (*s != ' ' && *s) {
            hashValue = (hashValue * PRIME + (int) *s) % M;
            str[count++] = *(s++);
        }
        str[count] = 0;
        if (!strlen(hash[hashValue])) {
            strcpy(hash[hashValue], str);
            added[hashValue] = true;
        } else {
            while (strlen(hash[hashValue])) {
                if (!strcmp(str, hash[hashValue])) {
                    if (added[hashValue]) {
                        added[hashValue] = false;
                    }
                    break;
                }
                hashValue++;
            }
            if (!strlen(hash[hashValue])) {
                strcpy(hash[hashValue], str);
                added[hashValue] = true;
            }
        }
        if (!*(s++)) {
            break;
        }
    }
}