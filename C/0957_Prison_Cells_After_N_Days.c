int* prisonAfterNDays(int* cells, int cellsSize, int N, int* returnSize) {
    *returnSize = cellsSize;
    int* cells1 = malloc(32);
    int* returnSize1 = malloc(32);
    returnSize1[0] = returnSize1[7] = 0;
    for (int i = 1; i < 7; i++) {
        if (cells[i - 1] == cells[i + 1]) {
            returnSize1[i] = 1;
        } else {
            returnSize1[i] = 0;
        }
    }
    for (int i = 0; i < 8; i++) {
        cells1[i] = returnSize1[i];
    }
    N = (N - 1) % 14 + 1;
    if (N == 1)
        return cells1;

    for (int j = 0; j < N - 1; j++) {
        for (int i = 1; i < 7; i++) {
            if (cells1[i - 1] == cells1[i + 1]) {
                returnSize1[i] = 1;
            } else {
                returnSize1[i] = 0;
            }
        }
        for (int i = 0; i < 8; i++) {
            cells1[i] = returnSize1[i];
        }
    }
    return cells1;
}