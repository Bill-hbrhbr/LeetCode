static void quickSort(int* A, int i, int j);
static void swap(int* A, int i, int j);

int sumSubseqWidths(int* A, int ASize) {
    const int LIMIT = pow(10, 9) + 7;
    srand((unsigned) time(NULL));
    quickSort(A, 0, ASize - 1);
    long result = 0, exponent = 1;
    for (int i = 0; i < ASize; i++) {
        //printf("A[%d] = %d\n", i, A[i]);
        result += (A[i] - A[ASize - 1 - i]) * exponent;
        result %= LIMIT;
        exponent = (exponent * 2) % LIMIT;
    }
    return result;
}

static void quickSort(int* A, int i, int j) {
    int low = i, high = j;
    if (i >= j) {
        return;
    }
    int pivot = rand() % (j - i + 1) + i;
    while (i < j) {
        while (A[i] <= A[pivot] && i != pivot) {
            i++;
        }
        while (A[j] >= A[pivot] && j != pivot) {
            j--;
        }
        if (i == j) {
            break;
        }
        if (i == pivot) {
            pivot = j;
        } else if (j == pivot) {
            pivot = i;
        }
        swap(A, i, j);
    }
    quickSort(A, low, pivot - 1);
    quickSort(A, pivot + 1, high);
}

static void swap(int* A, int i, int j) {
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}