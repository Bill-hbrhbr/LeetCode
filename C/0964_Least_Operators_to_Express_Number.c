#include "stdbool.h"

int recursive(int x, int target);

int leastOpsExpressTarget(int x, int target) {
    return recursive(x, target);
}

int recursive(int x, int target) {
    static int op = 1;
    static bool first = true;
    if (first) {
        first = false;
        int mod = target % x;
        int a = recursive(x, target / x);
        int b = recursive(x, target / x + 1);
        a += 2 * mod;
        b += 2 * (x - mod);
        return a < b ? (a - 1) : (b - 1);
    }
    if (target == 0) {
        return 0;
    }
    if (target == 1) {
        return op;
    }
    while (target % x == 0) {
        target /= x;
        op++;
    }
    int mod = target % x;
    op++;
    int a = recursive(x, target / x);
    int b = recursive(x, target / x + 1);
    op--;
    a += mod * op;
    b += (x- mod) * op;
    return a < b ? a : b;   
}

