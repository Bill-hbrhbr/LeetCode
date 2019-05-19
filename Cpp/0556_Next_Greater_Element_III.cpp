class Solution {
public:
    int nextGreaterElement(int n) {
        if (n <= 11) {
            return -1;
        }
        long long result = 0;
        vector<int> count(10, 0);
        vector<int> digits;
        bool found;
        int digit, i;
        while (n > 0) {
            digit = n % 10;
            found = false;
            for (i = digit + 1; i < 10; ++i) {
                if (count[i] > 0) {
                    found = true;
                    break;
                }
            }
            ++count[digit];
            digits.push_back(digit);
            n /= 10;
            if (found) {
                result = n * 10 + i;
                --count[i];
                for (int j = 0; j < 10; ++j) {
                    while (count[j] > 0) {
                        result = result * 10 + j;
                        --count[j];
                    }
                }
                return result > INT_MAX ? -1 : result;
            }
        }
        return -1;
    }
};