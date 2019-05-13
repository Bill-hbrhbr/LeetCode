static void swap(int* A, int index1, int index2);
static void bubbleDown(int* A, int i, int ASize);

int smallestRangeII(int* A, int ASize, int K) {
    int i, j, diff1, diff2, max, min;
    for (i = ASize - 1; i > 0; i--) {
        bubbleDown(A, i, ASize);
    }
    for (i = 1; i < ASize; i++) {
        swap(A, 0, ASize - i);
        bubbleDown(A, 1, ASize - i);
    }
    
    diff1 = A[ASize - 1] - A[0];
    for (i = 0; i < ASize - 1; i++) {
        A[i] += 2 * K;
        max = A[i] > A[ASize - 1] ? A[i] : A[ASize - 1];
        min = A[i + 1] < A[0] ? A[i + 1] : A[0];
        diff2 = max - min;
        if (diff2 < diff1) {
            diff1 = diff2;
        }
    }
    return diff1;
}


static void bubbleDown(int* A, int i, int ASize) {
    while (i * 2 < ASize) {
        if (A[i - 1] < A[i * 2 - 1]) {
            if (A[i* 2 - 1] < A[i * 2]) {
                swap(A, i - 1, i * 2);
                i = i * 2 + 1;
            } else {
                swap(A, i - 1, i * 2 - 1);
                i = i * 2;
            }
        } else if (A[i - 1] < A[i * 2]) {
            swap(A, i - 1, i * 2);
            i = i * 2 + 1;
        } else {
            return;
        }
    }
    if (i * 2 == ASize && A[i - 1] < A[i * 2 - 1]) {
        swap(A, i - 1, i * 2 - 1);
    }
}

static void swap(int* A, int index1, int index2) {
    int temp = A[index1];
    A[index1] = A[index2];
    A[index2] = temp;
    return;
}