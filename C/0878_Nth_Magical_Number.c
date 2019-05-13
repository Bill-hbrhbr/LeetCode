#define LIMIT (10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 + 7)
int get_GCD(int, int);
int calculate_remainder(int, int, int);

int nthMagicalNumber(int N, int A, int B) {
    int gcd = get_GCD(A, B);
    int lcm = A * B / gcd;
    //printf("lcm = %d\n", lcm);
    int count = A / gcd + B / gcd - 1;
    int mul = N / count;
    int remainder = N % count;
    if (!remainder) {
        return calculate_remainder(mul, lcm, 0);
    }
    int i = 1, j = 1;
    while (remainder > 1) {
        i * A < j * B ? i++ : j++;
        remainder--;
    }
    int extra = i * A < j * B ? i * A : j * B;
    return calculate_remainder(mul, lcm, extra);
}

int get_GCD(int a, int b) {
    int temp;
    while (1) {
        a = a % b;
        temp = a;
        a = b;
        b = temp;
        if (!b)
            return a;
    }
}

int calculate_remainder(int mul, int lcm, int extra) {
    int sum = 0;
    int count_to_limit = LIMIT / lcm + 1;
    int remainder = (count_to_limit * lcm) % LIMIT;
    while (mul >= count_to_limit) {
        sum = (sum + remainder) % LIMIT;
        mul -= count_to_limit;
    }
    return (sum + mul * lcm + extra) % LIMIT;
}