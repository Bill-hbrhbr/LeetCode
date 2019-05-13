int shortestSubarray(int* A, int ASize, int K) {
    int minLength = ASize + 1, array_sum = 0, reverse_max, reverse_sum, array_length;
    int *array_start = A, *array_end = A, *reverse_pointer;
    while (array_end < A + ASize) {
        array_sum += *array_end;
        if (array_sum <= 0) {
            array_sum = 0;
            array_start = ++array_end;
            continue;
        }
        if (array_sum >= K) {
            reverse_pointer = array_end;
            array_length = 1;
            reverse_sum = reverse_max = 0;
            array_start = array_end;
            while (array_length < minLength) {
                reverse_sum += *reverse_pointer;
                if (reverse_sum >= K)
                    break;
                if (reverse_sum > reverse_max) {
                    reverse_max = reverse_sum;
                    array_start = reverse_pointer;
                }
                reverse_pointer--;
                array_length++;
            }
            array_sum = reverse_max;
            if (minLength > array_length)
                minLength = array_length;
        }
        array_end++;
    }
    return minLength == ASize + 1 ? -1 : minLength;
}
