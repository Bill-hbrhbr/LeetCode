class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n < 0) {
            return 0;
        }
        if (n == 0) {
            return 1;
        }
        int total = 10, cur;
        for (int i = 1; i < n; ++i) {
            cur = 9;
            for (int j = i; j > 0; --j) {
                cur *= (10 - j);
            }
            total += cur;
        }
        return total;
    }
};