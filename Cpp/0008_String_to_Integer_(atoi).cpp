#include <cmath>
class Solution {
public:
    inline bool isDigit(char &ch) {
        if (ch >= '0' && ch <= '9') {
            return true;
        } else {
            return false;
        }
    }
    int myAtoi(string str) {
        long long n = 0;
        char ch;
        int sign;
        unsigned index = 0;
        while (index < str.size() && str[index] == ' ') {
            ++index;
        }
        if (index == str.size()) {
            return 0;
        } else if (str[index] == '+') {
            sign = 1;
            ++index;
        } else if (str[index] == '-') {
            sign = -1;
            ++index;
        } else if (!isDigit(str[index])) {
            return 0;
        } else {
            sign = 1;
        }
        while (index < str.size() && isDigit(str[index])) {
            n = n * 10 + (str[index] - '0');
            if (sign == 1 && n * sign > INT_MAX) {
                return INT_MAX;
            }
            if (sign == -1 && n * sign < INT_MIN) {
                return INT_MIN;
            }
            ++index;
        }
        return static_cast<int> (sign * n);
    }
};